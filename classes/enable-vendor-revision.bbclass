#
# Copyright (C) 2024 Wind River Systems, Inc
#
# SPDX-License-Identifier: GPL-2.0
#

python() {
    """
    Set PR:append = "VENDOR_REVISION" for the recipes
    """

    # Skip native recipes/cross related recipes
    if bb.data.inherits_class('native', d) or bb.data.inherits_class('nativesdk', d) or \
        bb.data.inherits_class('cross', d) or bb.data.inherits_class('crosssdk', d):
        return

    pn = d.getVar('PN')

    # For multilib recipes
    mlprefix = d.getVar('MLPREFIX')
    if mlprefix and pn.startswith(mlprefix):
        pn = pn[len(mlprefix):]

    # Directly use VENDOR_REVISION if the recipe sets it.
    vr = d.getVar('VENDOR_REVISION')
    if vr:
        d.appendVar('PR', vr)
        return

    pepv = '%s%s' % (d.getVar('PE'), d.getVar('PV'))
    # The ~ can't be a dict key
    if '~' in pepv:
        pepv = pepv.replace('~', '_tilde_')
    key = '%s_%s' % (pn, pepv)
    val = d.getVarFlag('VENDOR_REVISION', key)
    if val:
        # The first item is VENDOR_REVISION
        vr = val.split()[0]
        if vr:
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
