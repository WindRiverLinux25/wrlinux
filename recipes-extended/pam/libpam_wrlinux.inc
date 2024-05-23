#
# Add a few "redhat" modules to pam.  Some have been accepted upstream and
# are part of the distribution, but not the three we add here.
#

FILESEXTRAPATHS:prepend := "${THISDIR}/libpam:"

SRC_URI += "https://src.fedoraproject.org/repo/pkgs/pam/pam-redhat-1.3.0.tar.xz/sha512/1e17f5c9653d33eafc0070f57b7c7637f36689432c08c63d98a816d073e58b35a6711477eb559a216c4e98c694a75d5febafc68aa967e090e8c97602c0bef362/pam-redhat-1.3.0.tar.xz;name=redhat \
            file://0001-modules-meson.build-enable-build-redhat-pam-modules.patch \
            file://0002-modules-pam_postgresok-change-uid-to-28.patch \
            ${@bb.utils.contains('PACKAGECONFIG', 'faillock', 'file://pam_faillock_add_uid.patch', '', d)} \
           "

SRC_URI[redhat.sha256sum] = "d112f0abf253552657adb8196cc4711bed4d5cb0edff1210c6b98fd509ca598b"

# If necessary, move pam-redhat modules to where they will be built.
# We create a local function and use sh.
#
do_lcl_rh_move () {
    SAVED_PWD=`pwd`; cd ${S}
    if [ ! -e modules/pam_chroot ] ; then
        mv ${UNPACKDIR}/pam-redhat-1.3.0/* modules/
    fi
    cd ${SAVED_PWD}
}

# Now, we define our own do_patch.  We rely on the fact
# that the default do_patch just invokes patch_do_patch.
#
python do_patch () {
    bb.build.exec_func('do_lcl_rh_move', d)
    bb.build.exec_func('patch_do_patch', d)
}

do_install:append() {
    if ${@bb.utils.contains('PACKAGECONFIG', 'faillock', 'true', 'false', d)}; then
        sed -i '/end of pam-auth-update config/i \
# faillock is required to reset the fail count on success\
account    required            pam_faillock.so' \
            ${D}${sysconfdir}/pam.d/common-account
        sed -i '/pam_unix.so/i \
auth    required    pam_faillock.so preauth deny=5 even_deny_root unlock_time=60' \
            ${D}${sysconfdir}/pam.d/common-auth
        sed -i '/pam_unix.so/a \
auth    [default=die]    pam_faillock.so authfail deny=5 even_deny_root unlock_time=60 \
auth    sufficient       pam_faillock.so authsucc deny=5 even_deny_root unlock_time=60' \
            ${D}${sysconfdir}/pam.d/common-auth
    fi

    if ${@bb.utils.contains('DISTRO_FEATURES','sysvinit','false','true',d)}; then
        install -d ${D}${sysconfdir}/tmpfiles.d
        echo "d /run/console 0755 root root - -" >>  ${D}${sysconfdir}/tmpfiles.d/pam.conf
        if ${@bb.utils.contains('PACKAGECONFIG', 'faillock', 'true', 'false', d)}; then
            echo "d /run/faillock 0755 root root - -" >>  ${D}${sysconfdir}/tmpfiles.d/pam.conf
        fi
    else
        echo "d root root 0755 /var/run/console none" >> ${D}${sysconfdir}/default/volatiles/99_pam
        if ${@bb.utils.contains('PACKAGECONFIG', 'faillock', 'true', 'false', d)}; then
            echo "d root root 0755 /var/run/faillock none" >> ${D}${sysconfdir}/default/volatiles/99_pam
        fi
    fi
}

PACKAGECONFIG[faillock] = ",,,"
RDEPENDS:${PN}-runtime += "${@bb.utils.contains('PACKAGECONFIG', 'faillock', 'pam-plugin-faillock', '', d)}"
