#
# Copyright (C) 2020, 2026 Wind River Systems, Inc.
#
# Check and warn for the externally downloadable 3rd party components for
# the recipes which are in Wind River Linux but not supported.
#
# INHERIT += "third-party-dl"
#
# Print warning for:
# WRL_RECIPE_VERSION[PN] = "N": In WRLinux, but not supported.
#
# No warning for:
# - WRL_RECIPE_VERSION[PN] is None: Not in WRLinux
# - WRL_RECIPE_VERSION[PN] = "<PV>": Supported
# - WRL_RECIPE_VERSION[PN] = "I": Ignored
#
# Support extending wrlinux recipes for some special layers
#
# Usage:
# EXTENDED_WRL_RECIPE_VERSION += "conf/layername-recipe-version.inc"
#

require conf/wrlinux-recipe-version.inc
EXTENDED_WRL_RECIPE_VERSION ??= ""
include ${EXTENDED_WRL_RECIPE_VERSION}

do_fetch[prefuncs] += "third_party_dl"

THIRD_PARTY_DL_CHECK ??= "1"
THIRD_PARTY_DL_MSG_COMMON = "Check 'Externally downloadable 3rd party components' in EULA for more information. You can set WRL_RECIPE_VERSION[${BPN}] = 'I' to ignore the warning at your own risk"
THIRD_PARTY_DL_MSG_PN ?= "${PN} is not supported by Wind River Linux. ${THIRD_PARTY_DL_MSG_COMMON}"
THIRD_PARTY_DL_MSG_PV ?= "${PV} is not supported by Wind River Linux. ${THIRD_PARTY_DL_MSG_COMMON}"

python() {
    deps = ""
    for n in (d.getVar('PN'), d.getVar('BPN')):
        deps += ' %s' % d.getVarFlag("WRL_RECIPE_VERSION", n)
        deps += ' %s' % d.getVar('WRLINUX_SUPPORTED_RECIPE:pn-%s' % n)
    d.appendVarFlag("do_fetch", "vardeps", deps)
}

python third_party_dl() {
    tdc = d.getVar('THIRD_PARTY_DL_CHECK')
    if tdc not in ('0', '1'):
        bb.warn('THIRD_PARTY_DL_CHECK should be "0" or "1", but it is "%s"' % tdc)
        return

    if tdc == '0':
        bb.note('THIRD_PARTY_DL_CHECK is not set, skip the checking')
        return

    pn = d.getVar('PN')
    bpn = d.getVar('BPN')
    support = d.getVarFlag('WRL_RECIPE_VERSION', pn) or d.getVarFlag('WRL_RECIPE_VERSION', bpn) or ''
    # Make the following previous settings can ignore the warnings:
    # WRLINUX_SUPPORTED_RECIPE:pn-<PN> = "2"
    ignore = d.getVar('WRLINUX_SUPPORTED_RECIPE:pn-%s' % pn) or d.getVar('WRLINUX_SUPPORTED_RECIPE:pn-%s' % bpn) or ''
    ignore = ignore.strip()
    # Not in WRLinux
    if not support:
        bb.debug(1, '%s is not in WRLinux' % pn)
    # Ignored
    elif support == 'I' or ignore == '2':
        bb.debug(1, 'Ignore checking for %s' % pn)
    elif support == 'N':
        bb.warn(d.getVar('THIRD_PARTY_DL_MSG_PN'))
    else:
        pv = d.getVar('PV')
        if not pv in support.split():
            bb.warn(d.getVar('THIRD_PARTY_DL_MSG_PV'))
}
