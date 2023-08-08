#
# Copyright (C) 2022-2023 Wind River Systems, Inc.
#

pkg_postinst:${PN}:append() {
    if ! ${@bb.utils.contains('DISTRO_FEATURES','wr-allow-wired-default','true','false',d)}; then
        mkdir -p $D${sysconfdir}/systemd/network
        ln -sf /dev/null $D${sysconfdir}/systemd/network/80-wired.network
    fi
}
