#
# Copyright (C) 2025 Wind River Systems, Inc.
#
# SPDX-License-Identifier: MIT
#

python do_create_spdx:prepend() {
    import oe.packagedata

    purl_qualifiers = "distro=%s-%s&arch=%s" % ("yocto" if d.getVar("DISTRO") == "poky" else d.getVar("DISTRO"), \
                                                d.getVar("DISTRO_VERSION"), \
                                                d.getVar("MACHINE"), \
                                                )
    purl_qualifiers_extend = d.getVar("SPDX_PURL_QUALIFIERS_EXTEND")
    if purl_qualifiers_extend:
        purl_qualifiers += "&%s" % purl_qualifiers_extend

    purl_type = d.getVar("IMAGE_PKGTYPE")
    if purl_type == "ipk":
        purl_type = "yocto"
        purl_qualifiers = "file_extension=ipk&" + purl_qualifiers

    purl_subpath = d.getVar("SPDX_PURL_SUBPATH")
    purl_subpath = "#" + purl_subpath if purl_subpath else ""

    bb.build.exec_func("read_subpackage_metadata", d)

    for package in d.getVar("PACKAGES", True).split():
        if not oe.packagedata.packaged(package, d):
            continue
        pkg_name = d.getVar("PKG:%s" % package) or package
        purl = "pkg:%s/%s/%s@%s?%s%s" % (purl_type, \
                                     d.getVar("DISTRO"), \
                                     pkg_name, \
                                     d.getVar("EXTENDPKGV"), \
                                     purl_qualifiers, \
                                     purl_subpath \
                                     )

        d.setVar("SPDX_PACKAGE_URL:%s" % package, purl)
}
