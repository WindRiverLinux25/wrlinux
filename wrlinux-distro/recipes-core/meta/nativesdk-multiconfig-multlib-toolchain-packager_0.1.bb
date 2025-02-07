DESCRIPTION = "Fetch 32bit x86 buildtools-tarball from x86 multiconfig build, \
extract and install toolchain libraries and include files into 64bit nativesdk sysroot.\
Or fetch 64bit x86_64 buildtools-tarball from x86_64 multiconfig build, \
extract and install toolchain libraries and include files into 32bit nativesdk sysroot.\
"
LICENSE = "GPL-2.0-only"
LIC_FILES_CHKSUM ?= "file://${COMMON_LICENSE_DIR}/GPL-2.0-only;md5=801f80980d171dd6425610833a22dbe6"

inherit nativesdk

MCSDK_ARCH:virtclass-mcextend-x86 = "i686"
MCSDK_ARCH:virtclass-mcextend-x86_64 = "x86_64"

FROM_MULTICONFIG:virtclass-mcextend-x86_64 = "x86"
FROM_MULTICONFIG:virtclass-mcextend-x86 = "x86_64"

TO_MULTICONFIG = "${MCNAME}"

MC_SDK_DEPLOY = "${TOPDIR}/tmp-mc-${MCNAME}/deploy/sdk"
MC_TOOLCHAIN_OUTPUTNAME = "${MCSDK_ARCH}-buildtools-nativesdk-standalone-${DISTRO_VERSION}"

# 64bit x86_64 platform requires 32bit x86 buildtools-tarball
# Or
# 32bit x86 platform requires 64bit buildtools-tarball
do_install[mcdepends] += "mc:${FROM_MULTICONFIG}:${TO_MULTICONFIG}:buildtools-tarball:do_build"
do_install () {
    install -d ${D}${localstatedir}/machines/${MCNAME}
    install ${MC_SDK_DEPLOY}/${MC_TOOLCHAIN_OUTPUTNAME}.sh ${D}${localstatedir}/machines/${MCNAME}/buildtools-tarball.sh
}

MC_BASELIB:virtclass-mcextend-x86 = "lib"
MC_BASELIB:virtclass-mcextend-x86_64 = "lib64"

MC_BIT:virtclass-mcextend-x86 = "32"
MC_BIT:virtclass-mcextend-x86_64 = "64"

INSTALL_FILES ?= " \
    /usr/include/bits/endianness-${MC_BIT}.h \
    /usr/include/bits/floatn-${MC_BIT}.h \
    /usr/include/bits/long-double-${MC_BIT}.h \
    /usr/include/bits/math-vector-${MC_BIT}.h \
    /usr/include/bits/struct_rwlock-${MC_BIT}.h \
    /usr/include/bits/syscall-${MC_BIT}.h \
    /usr/include/gnu/lib-names-${MC_BIT}.h \
    /usr/include/gnu/stubs-${MC_BIT}.h \
    /usr/${MC_BASELIB} \
    /${MC_BASELIB} \
"
do_install[vardeps] += "INSTALL_FILES MC_SDK_DEPLOY MC_TOOLCHAIN_OUTPUTNAME"

# Extract and install toolchain libraries and include files into nativesdk sysroot
pkg_postinst:${PN} () {
    set -x
    $D${localstatedir}/machines/${MCNAME}/buildtools-tarball.sh -y -d $D/sdk-${MCNAME}
    src_prefix="$D/sdk-${MCNAME}/sysroots/${SDK_ARCH}${SDK_VENDOR}-${SDK_OS}"
    for install_file in ${INSTALL_FILES}; do
        if [ ! -e ${src_prefix}${install_file} ]; then
            echo "${src_prefix}${install_file} does not exist"
            exit 1
        elif [ -d ${src_prefix}${install_file} ]; then
            install -d $D${SDKPATHNATIVE}${install_file}
            cp -rf ${src_prefix}${install_file}/* $D${SDKPATHNATIVE}${install_file}/
        else
            install -d $D${SDKPATHNATIVE}${install_file%/*}
            cp -f ${src_prefix}${install_file} $D${SDKPATHNATIVE}${install_file}
        fi
    done
    rm $D/sdk-${MCNAME} $D${localstatedir}/machines/${MCNAME}/buildtools-tarball.sh -rf

    # this makes multilib gcc files findable for nativesdk gcc
    # to link multilib nativesdk gcc library
    # e.g.
    # For x86_64 nativesdk-libgcc
    #    sysroots/x86_64-pokysdk-linux/usr/lib/i686-pokysdk-linux/14.2.0
    # by creating this symlink to it
    #    sysroots/x86_64-pokysdk-linux/usr/lib64/x86_64-pokysdk-linux/14.2.0/32
    #
    # For i686 nativesdk-libgcc
    #    sysroots/i686-pokysdk-linux/usr/lib64/x86_64-pokysdk-linux/14.2.0
    # by creating this symlink to it
    #    sysroots/i686-pokysdk-linux/usr/lib/i686-pokysdk-linux/14.2.0/64
    if [ "${SDK_ARCH}" = "x86_64" ]; then
        tune_arch='i686'
        tune_bitness='32'
        tune_baselib='lib'
    elif [ "${SDK_ARCH}" = "i686" -o ${SDK_ARCH} = "i586" ]; then
        tune_arch='x86_64'
        tune_bitness='64'
        tune_baselib='lib64'
    fi
    binv="$(ls $D${libdir}/${SDK_SYS}/)"
    src="../../../${tune_baselib}/${tune_arch}${SDK_VENDOR}-${SDK_OS}/${binv}/"
    dest="$D${libdir}/${SDK_SYS}/${binv}/${tune_bitness}"
    (cd $D${libdir}/${SDK_SYS}/${binv} && ln -snf $src $dest)
}


python () {
    mcname = d.getVar('MCNAME')
    if not mcname:
        raise bb.parse.SkipRecipe("Not a multiconfig target")

    multiconfigs = d.getVar('BBMULTICONFIG') or ""
    if mcname not in multiconfigs:
        raise bb.parse.SkipRecipe("multiconfig target %s not enabled" % mcname)
}

INSANE_SKIP = "native-last"

BBCLASSEXTEND = "mcextend:x86 mcextend:x86_64"
