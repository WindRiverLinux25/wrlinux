#
# Copyright (C) 2024 Wind River Systems, Inc
#
# SPDX-License-Identifier: GPL-2.0
#

inherit enable-vendor-revision

VENDOR_REVISION_DIR ?= "${TMPDIR}/vendor-revisions/${MACHINE}"
VENDOR_REVISION_ALL ?= "${VENDOR_REVISION_DIR}/wrlinux-vendor-revision.conf"

# For fixed RCPL users which can be set in their own conf file such as
# conf/layer.conf, for example, ccm01 to ccm99:
#VENDOR_REVISION_SUFFIX = ".ccm01"
VENDOR_REVISION_SUFFIX ??= ""

addhandler gen_vr_prepare
gen_vr_prepare[eventmask] = "bb.event.CacheLoadStarted"
python gen_vr_prepare() {
    vendor_revision_dir = d.getVar('VENDOR_REVISION_DIR')
    # Need a fresh VENDOR_REVISION_DIR and CACHE dir
    for k in ('VENDOR_REVISION_DIR', 'CACHE'):
        value = d.getVar(k)
        bb.note("Removing %s" % value)
        bb.utils.remove(value, True)
        bb.utils.mkdirhier(value)
}

# Generate VENDOR_REVISION for each recipe
addhandler gen_vr_recipe_handler
gen_vr_recipe_handler[eventmask] = "bb.event.RecipeParsed"
python gen_vr_recipe_handler() {
    """
    Generate VENDOR_REVISION for each recipe, the format is:
    VENDOR_REVISION[recipe_file] ?= 'vr cveid1:patch1 notcve:patch2'
    """

    import hashlib

    if vr_need_skip(d):
        return

    # Only generate vr for supported recipes
    wrl_supported = d.getVar('WRLINUX_SUPPORTED_RECIPE')
    if wrl_supported and wrl_supported.strip() == '0':
        return

    def get_cve_patch(patch):
        ret = []
        patch_bn = os.path.basename(patch)
        # Open in 'text' mode doesn't work for very a few patches such as:
        # hddtemp_0.3-beta15-52.diff: 'utf-8' codec can't decode byte 0xe8 in
        # position 3851: invalid continuation byte
        with open(patch, 'rb') as f:
            # Get md5
            md5 = hashlib.md5()
            md5.update(f.read())
            hash = md5.hexdigest()
            patch_bn += ':%s' % md5.hexdigest()
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
                        if cveid.startswith('CVE-'):
                            ret.append('%s:%s' % (cveid, patch_bn))
        if not ret:
            ret.append('notcve:%s' % patch_bn)
        return ret

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

        file_short = get_file_short(d)
        vr = get_current_vendor_revision(d)
        old_val = d.getVarFlag('VENDOR_REVISION', file_short)

        # No checking is needed in the following cases:
        # - No old_val: It's a new vr, just update it
        # - len(old_vr) != len(vr): The vr has changed a lot such as
        #   VENDOR_REVISION_SUFFIX is newly defined, just update it.
        if old_val:
            old_vr = old_val.split()[0]
            if old_vr and len(old_vr) == len(vr):
                # In different RCPL, check whether need update
                if old_vr != vr:
                    old_patches = ' '.join(old_val.split()[1:])
                    # The patches are the same, no update is needed
                    if old_patches == new_patches:
                        vr = old_vr

        # Replace .vr -> ${VENDOR_REVISION_PREFIX}
        vr_prefix = d.getVar("VENDOR_REVISION_PREFIX") or ""
        vr = vr.removeprefix(vr_prefix)
        vr = '${VENDOR_REVISION_PREFIX}%s' % vr
        vr_out = "VENDOR_REVISION[%s] ??= '%s'" % (file_short, vr)
        if new_patches:
            vr_out = "VENDOR_REVISION[%s] ??= '%s %s'" % (file_short, vr, new_patches)
        out_file = os.path.join(d.getVar('VENDOR_REVISION_DIR'), file_short)
        with open(out_file, 'w') as f:
            f.write('%s\n' % vr_out)

    patches = []
    src_uri = d.getVar('SRC_URI')
    for s in src_uri.split():
        if s.endswith('.patch') or s.endswith('.diff'):
            if not s.startswith("file://"):
                continue
            fetcher = bb.fetch2.Fetch([s], d)
            local = fetcher.localpath(s)
            patches += get_cve_patch(local)
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
    nopatches = []
    output = d.getVar('VENDOR_REVISION_ALL')
    output_dir = os.path.dirname(output)
    for recipe in glob.glob(os.path.join(vendor_revision_dir, '*')):
        with open(recipe) as f:
            for line in f:
                if not line in (patches + nopatches):
                    line_split = line.split()
                    if len(line_split) > 3:
                        patches.append(line)
                    else:
                        nopatches.append(line)
    patches.sort()
    nopatches.sort()
    output_nopatches = os.path.join(output_dir, 'wrlinux-vendor-revision-nopatches.inc')
    with open(output, 'w') as f:
        f.write('require %s\n\n' % "wrlinux-vendor-revision-manual.inc")
        if nopatches:
            f.write('require %s\n\n' % os.path.basename(output_nopatches))
            with open(output_nopatches, 'w') as f2:
                f2.write(''.join(nopatches))
                bb.note('The recipes without patches are saved to %s' % output_nopatches)
        f.write(''.join(patches))
    bb.note('The recipes with patches are saved to %s' % output)
}
