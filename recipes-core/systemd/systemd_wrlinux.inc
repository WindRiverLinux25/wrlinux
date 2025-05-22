#
# Copyright (C) 2014-2024 Wind River Systems, Inc.
#
# LOCAL REV: add WR specific scripts
#

DEPENDS += "systemd-systemctl-native"

do_install:append() {
        # Enable all sysrq functions
        if ${@bb.utils.contains('DISTRO_FEATURES','systemdebug','true','false',d)}; then
                sed -i -e 's/^kernel\.sysrq *=.*/kernel\.sysrq = 1/' ${D}/${exec_prefix}/lib/sysctl.d/50-default.conf
        fi
}
