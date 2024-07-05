#
# Copyright (C) 2024 Wind River Systems, Inc
#
# SPDX-License-Identifier: GPL-2.0
#

VENDOR_REVISION_DIR ?= "${TMPDIR}/vendor-revisions"
VENDOR_REVISION_RECIPE ?= "${VENDOR_REVISION_DIR}/${PN}-${PV}"
VENDOR_REVISION_ALL ?= "${VENDOR_REVISION_DIR}/wrlinux-vendor-revision.conf"

# For fixed RCPL users which can be set in their own conf file such as
# conf/layer.conf, for example, ccm01 to ccm99:
#VENDOR_REVISION_SUFFIX = ".ccm01"
VENDOR_REVISION_SUFFIX ??= ""

# To avoid confusions with PR Server
VENDOR_REVISION_PREFIX ??= "vr"

# Find all patches in BBLAYERS
VENDOR_REVISION_ALL_PATCHES ?= ""

addhandler find_all_patches_handler
find_all_patches_handler[eventmask] = "bb.event.ConfigParsed"
python find_all_patches_handler() {
    """
    Find out all patches in BBLAYERS:
    - Get CVE id for CVE patches, the keyword is the line in patch
      header: "CVE: CVE-.*"
    - Use notcve as CVE id for non-CVE patches
    """
    import subprocess
    import hashlib

    layers = []
    for layer in d.getVar('BBLAYERS').split():
        # Skip dl layers
        if layer.endswith('-dl') or ('-dl-' in layer):
            bb.debug(1, 'Skipping download layer %s' % layer)
            continue
        layers.append(layer)

    cmd = "find %s -name '*.patch' -o -name '*.diff'" % ' '.join(layers)
    patches = subprocess.check_output(cmd, stderr=subprocess.STDOUT, shell=True).decode('utf-8')
    if not patches:
        bb.warn("No patches are found in BBLAYERS")
        return

    all_patches = {}
    all_patches['notcve'] = []
    bbpath = d.getVar('BBPATH')
    for patch in patches.split('\n'):
        patch = patch.strip()
        if not patch:
            continue

        # Open in 'text' mode doesn't work for very a few patches such as:
        # hddtemp_0.3-beta15-52.diff: 'utf-8' codec can't decode byte 0xe8 in
        # position 3851: invalid continuation byte
        with open(patch, 'rb') as f:
            found_cve = False
            patch_short = '/'.join(patch.split('/')[-5:])
            # Get md5
            md5 = hashlib.md5()
            md5.update(f.read())
            hash = md5.hexdigest()
            patch_short += ':%s' % hashlib.md5().hexdigest()
            # Reset file postion
            f.seek(0, 0)
            for line in f:
                if not 'CVE:' in str(line):
                    continue
                line = line.decode('utf-8')
                if line.startswith('CVE:') and 'CVE-' in line:
                    line_split = line.split('CVE:')
                    for cveid in line_split[1].split():
                        cveid = cveid.strip()
                        if not cveid.startswith('CVE-'):
                            continue
                        if cveid in all_patches:
                            if not patch_short in all_patches[cveid]:
                                all_patches[cveid].append(patch_short)
                        else:
                            all_patches[cveid] = [patch_short]
                        found_cve = True
            if not found_cve:
                all_patches['notcve'].append(patch_short)

    vendor_revision_dir = d.getVar('VENDOR_REVISION_DIR')
    # Need a fresh VENDOR_REVISION_DIR dir
    if os.path.exists(vendor_revision_dir):
        bb.note("Removing %s" % vendor_revision_dir)
        bb.utils.remove(vendor_revision_dir, True)
    bb.utils.mkdirhier(vendor_revision_dir)

    d.setVar('VENDOR_REVISION_ALL_PATCHES', all_patches)

    # Always parse, otherwise the vendor revision files may not generate
    cache = d.getVar('CACHE')
    if os.path.exists(cache):
        bb.note("Removing %s" % cache)
        bb.utils.remove(cache, True)
}

# Generate VENDOR_REVISION for each recipe
addhandler gen_vr_recipe_handler
gen_vr_recipe_handler[eventmask] = "bb.event.RecipeParsed"
python gen_vr_recipe_handler() {
    """
    Generate VENDOR_REVISION for each recipe, the format is:
    VENDOR_REVISION[pn_pepv] ?= 'vr cveid1:patch1 notcve:patch2'
    There might be multiple versions for a recipe, and different version may
    have different patches, so use pn_pepv_vr as the dict key to avoid
    conflicts, and manage them separately.
    """

    # Skip native recipes/cross related recipes
    if bb.data.inherits_class('native', d) or bb.data.inherits_class('nativesdk', d) or \
        bb.data.inherits_class('cross', d) or bb.data.inherits_class('crosssdk', d):
        return

    all_patches = d.getVar('VENDOR_REVISION_ALL_PATCHES')
    def get_vendor_revision():
        year_version = d.getVar('WRLINUX_YEAR_VERSION')
        if not year_version:
            bb.warn('Failed to get WRLINUX_YEAR_VERSION')
            year_version = '0'
        update_version = d.getVar('WRLINUX_UPDATE_VERSION') or '0'
        if int(update_version) <10:
            # Prepend 0 when less than 10
            update_version = '0%s' % update_version

        vendor_revision = '%s%s' % (year_version, update_version)

        vr_suffix = d.getVar('VENDOR_REVISION_SUFFIX') or ''
        if vr_suffix:
            vendor_revision += vr_suffix

        vendor_revision_prefix = d.getVar('VENDOR_REVISION_PREFIX')
        return '%s%s' % (vendor_revision_prefix, vendor_revision)

    def get_cve_patch(patch):
        """
        Return CVE id and patch_short
        """
        for (cveid, patches) in all_patches.items():
            for patch_short in patches:
                patch_short_bn = os.path.basename(patch_short.split(':')[0])
                if patch == patch_short_bn:
                    return cveid, patch_short

        return '', ''

    def update_vr(patches):
        """
        Check whether recipe's VENDOR_REVISION need update or not
        * If old_vr == new_vf
          - No check is needed since they are in the same
            RCPL, just update it.

        * If old_vr != new_vr:
          - If the patches are the same:
            Nothing changed, use the old_vr to avoid unneeded updates by dnf.

          - If the patches are different:
            Update to the new_vr
        """

        patches.sort()
        new_patches = ' '.join(patches)
        pepv = '%s%s' % (d.getVar('EXTENDPE'), d.getVar('PV'))
        # The ~ can't be a dict key
        if '~' in pepv:
            pepv = pepv.replace('~', '_tilde_')
        pn = d.getVar('PN')

        # There might be multiple versions for a recipe, so use 'pv:pepv'
        # as the dict key to separate them
        key = '%s_%s' % (pn, pepv)
        vr = '.%s' % get_vendor_revision()
        old_val = d.getVarFlag('VENDOR_REVISION', key)

        # No checking is needed in the following cases:
        # - No old_val: It's a new vr, just update it
        # - len(old_vr) != len(vr): The vr has changed a lot such as
        #   VENDOR_REVISION_SUFFIX is newly defined, just update it.
        if old_val:
            old_vr = old_val.split()[0]
            if old_vr and len(old_vr) == len(vr):
                # In different RCPL, check whether need update
                if old_vr != vr:
                    old_cves = ' '.join(old_val.split()[1:])
                    # The cve patches are the same, no update is needed
                    if old_cves == new_patches:
                        vr = old_vr

        vr_out = "VENDOR_REVISION[%s] ?= '%s %s'" % (key, vr, new_patches)
        with open(d.getVar('VENDOR_REVISION_RECIPE'), 'w') as f:
            f.write('%s\n' % vr_out)

    patches = []
    for s in (d.getVar('SRC_URI') or '').split():
        if s.endswith('.patch') or s.endswith('.diff'):
            s = s.replace('file://', '').strip()
            cveid, patch_short = get_cve_patch(s)
            if cveid:
                patches.append('%s:%s' % (cveid, patch_short))
    update_vr(patches)
}

# Generate vendor-revision.conf
addhandler gen_vr_all_handler
gen_vr_all_handler[eventmask] = "bb.event.ParseCompleted"
python gen_vr_all_handler () {
    """
    Collect each recipe's vendor revision in VENDOR_REVISION_DIR and save
    to VENDOR_REVISION_ALL
    """
    import glob
    vendor_revision_dir = d.getVar('VENDOR_REVISION_DIR')
    patches = []
    output = d.getVar('VENDOR_REVISION_ALL')
    output_bn = os.path.basename(output)
    for recipe in glob.glob(os.path.join(vendor_revision_dir, '*')):
        # Just in case there is a vendor-revision.conf
        if output_bn in recipe:
            continue
        with open(recipe) as f:
            patches += f.readlines()
    patches.sort()
    with open(output, 'w') as f:
        f.write(''.join(patches))
    bb.note('The result is saved to %s' % output)
}
