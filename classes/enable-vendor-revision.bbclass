#
# Copyright (C) 2024 Wind River Systems, Inc
#
# SPDX-License-Identifier: GPL-2.0
#

# To avoid confusions with PR Server
VENDOR_REVISION_PREFIX ??= ".vr"

def vr_need_skip(d):

    packages = d.getVar('PACKAGES')
    if (not packages) or bb.data.inherits_class('nopackages', d) or \
             bb.data.inherits_class('nativesdk', d):
        return True

    # VR only makes sense when there are sources
    if not d.getVar('SRC_URI'):
        return True

def get_file_short(d):
    return '/'.join(d.getVar('FILE').split('/')[-4:]).replace('/', '_')

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

    vr_suffix = d.getVar('VENDOR_REVISION_SUFFIX') or ''
    if vr_suffix:
        vendor_revision += vr_suffix

    return vendor_revision

python() {
    """
    Set PR:append = "VENDOR_REVISION" for the recipes
    """

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
