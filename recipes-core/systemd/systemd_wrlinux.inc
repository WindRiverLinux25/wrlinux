#
# Copyright (C) 2014-2024 Wind River Systems, Inc.
#
# LOCAL REV: add WR specific scripts
#

DEPENDS += "systemd-systemctl-native"

# conditionally suppress predicatable network interface names
#
pkg_postinst:udev:append() {
        if ! ${@bb.utils.contains('DISTRO_FEATURES','pni-names','true','false',d)}; then
		ln -sf /dev/null $D${sysconfdir}/udev/rules.d/80-net-setup-link.rules
	fi
}

do_install:append() {
        # Enable all sysrq functions
        if ${@bb.utils.contains('DISTRO_FEATURES','systemdebug','true','false',d)}; then
                sed -i -e 's/^kernel\.sysrq *=.*/kernel\.sysrq = 1/' ${D}/${exec_prefix}/lib/sysctl.d/50-default.conf
        fi
}
