FILESEXTRAPATHS:prepend := "${THISDIR}/files:"

LOGO = "${datadir}/plymouth/wrl.png"

SRC_URI += " \
	file://wrl.png \
	file://windriver.plymouth \
	file://windriver.script \
	file://plymouthd.conf \
	file://plymouthd.defaults \
"

do_install:append() {
    install -d ${D}${datadir}/plymouth/themes/windriver
    install -m 0644 ${UNPACKDIR}/windriver.plymouth   ${D}${datadir}/plymouth/themes/windriver/
    install -m 0644 ${UNPACKDIR}/windriver.script   ${D}${datadir}/plymouth/themes/windriver/
    install -m 0644 ${UNPACKDIR}/wrl.png   ${D}${datadir}/plymouth/themes/windriver/
    install -m 0644 ${UNPACKDIR}/wrl.png ${D}${datadir}/plymouth
    install -m 0644 ${UNPACKDIR}/plymouthd.conf ${D}${sysconfdir}/plymouth/
    install -m 0644 ${UNPACKDIR}/plymouthd.defaults ${D}${datadir}/plymouth/

}
