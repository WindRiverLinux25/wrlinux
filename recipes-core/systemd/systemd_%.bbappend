# This file is generated automatically by wry
SYSTEMD_INC_WRLINUX = ""
SYSTEMD_INC_WRLINUX:osv-wrlinux = "systemd_wrlinux.inc"
require ${SYSTEMD_INC_WRLINUX}
require ${@bb.utils.contains('DISTRO_FEATURES', 'ostree', '${BPN}_ostree.inc', '', d)}
