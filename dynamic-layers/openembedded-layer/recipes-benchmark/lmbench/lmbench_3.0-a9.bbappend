#
# Copyright (C) 2014 Wind River Systems, Inc.
#

FILESEXTRAPATHS:prepend := "${THISDIR}/${P}:"

SRC_URI += "file://lmbench-3.0-a9_wr_integration.patch \
            file://wr-lmbench-test.sh \
            file://dealt_log.sh \
            file://README \
            file://generate_report.sh \
            file://scripts/sysinfo_lib.sh \
            file://scripts/utility.sh \
            file://config/default_case_conf \
            file://config/default_group_conf \
"

WR_LMBENCH ?= "/opt/benchmark/os/wr-lmbench"

inherit update-alternatives

do_install:append () {
	install -d ${D}/${WR_LMBENCH}
	install -m 0755 ${UNPACKDIR}/wr-lmbench-test.sh ${D}/${WR_LMBENCH}
	install -m 0755 ${UNPACKDIR}/dealt_log.sh ${D}/${WR_LMBENCH}
	install -m 0755 ${UNPACKDIR}/generate_report.sh ${D}/${WR_LMBENCH}
	install -m 0664 ${UNPACKDIR}/README ${D}/${WR_LMBENCH}/
	cp -r ${UNPACKDIR}/config ${D}/${WR_LMBENCH}/
	cp -r ${UNPACKDIR}/scripts ${D}/${WR_LMBENCH}/
	mv ${D}${bindir}/hello ${D}${bindir}/hello.lmbench
}

ALTERNATIVE:${PN} = "hello"
ALTERNATIVE_PRIORITY = "100"
ALTERNATIVE_LINK_NAME[hello] = "${bindir}/hello"
ALTERNATIVE_TARGET[hello] = "${bindir}/hello.lmbench"

FILES:${PN} += "${WR_LMBENCH}"

RDEPENDS:${PN} += "bash"
