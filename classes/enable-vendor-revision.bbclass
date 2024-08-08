#
# Copyright (C) 2024 Wind River Systems, Inc
#
# SPDX-License-Identifier: GPL-2.0
#

# To avoid confusions with PR Server
VENDOR_REVISION_PREFIX ??= ".vr"

def get_src_patches(d):
    import oe.patch
    local_patches = set()
    for patch in oe.patch.src_patches(d):
        _, _, local, _, _, parm = bb.fetch.decodeurl(patch)
        local_patches.add(local)
    return local_patches

def is_work_shared(d):
    sharedworkdir = os.path.join(d.getVar('TMPDIR'), 'work-shared')
    return d.getVar('S').startswith(sharedworkdir)

def vr_need_skip(d):

    if is_work_shared(d):
        return False

    packages = d.getVar('PACKAGES')
    if (not packages) or bb.data.inherits_class('nopackages', d) or \
             bb.data.inherits_class('nativesdk', d):
        return True

    # Skip VR when no patches
    if get_src_patches(d):
        return False
    else:
        return True

def get_var_short(var):
    return '/'.join(var.split('/')[-4:]).replace('/', '_')

def get_file_short(d):
    return get_var_short(d.getVar('FILE'))

def get_current_vendor_revision(d):
    year_version = d.getVar('WRLINUX_YEAR_VERSION')
    if not year_version:
        bb.warn('Failed to get WRLINUX_YEAR_VERSION')
        year_version = '0'
    update_version = d.getVar('WRLINUX_UPDATE_VERSION') or '0'
    if int(update_version) <10:
        # Prepend 0 when less than 10
        update_version = '0%s' % update_version

    vendor_revision = '%s%s' % (year_version, update_version)

    vr_prefix = d.getVar('VENDOR_REVISION_PREFIX') or ''
    if vr_prefix:
        vendor_revision = vr_prefix + vendor_revision

    vr_suffix = d.getVar('VENDOR_REVISION_SUFFIX') or ''
    if vr_suffix:
        vendor_revision += vr_suffix

    return vendor_revision

python() {
    """
    Set PR:append = "VENDOR_REVISION" for the recipes
    """

    # Skip when gen-vendor-revision is inherited
    if bb.data.inherits_class('gen-vendor-revision', d):
        bb.debug(1, 'Skipping enabling VR for %s since gen-vendor-revision is inherited' % d.getVar('PN'))
        return

    if vr_need_skip(d):
        return

    # Directly use VENDOR_REVISION if the recipe sets it.
    vr = d.getVar('VENDOR_REVISION')
    if not vr:
        file_short = get_file_short(d)
        val = d.getVarFlag('VENDOR_REVISION', file_short)
        if val:
            # The first item is VENDOR_REVISION
            vr = val.split()[0]
            # The d.getVarFlag("VENDOR_REVISION", "tmp-glibc_work-shared_qemux86-64_kernel-source")
            # return None when kernel doesn't have patches, and vr_need_skip()
            # can't skip work-shared recipes. The None is a string here.
            if vr == 'None':
                return

    if not vr:
        # It's a new recipe, defult to current VR
        vr = get_current_vendor_revision(d)

    bb.debug(1, 'Appending VENDOR_REVISION %s to PR' % vr)
    d.appendVar('PR', vr)
}

GLOBAL_VENDOR_REVISION_WARN ??= '1'
addhandler warn_for_global_vr
warn_for_global_vr[eventmask] = "bb.event.ConfigParsed"
python warn_for_global_vr() {
    # The VENDOR_REVISION should be set via recipe level, otherwise, there
    # might be PR bombs or no effect, so warn for global VENDOR_REVISION
    global_vr = d.getVar('VENDOR_REVISION')
    if global_vr and bb.utils.to_boolean(d.getVar('GLOBAL_VENDOR_REVISION_WARN')):
        bb.warn('The global VENDOR_REVISION (%s) may cause unneeded packages upgrading,' % global_vr)
        bb.warn('or make VENDOR_REVISION invalid.')
        bb.warn('The above warning can be disabled by GLOBAL_VENDOR_REVISION_WARN = "0"\n')
}
