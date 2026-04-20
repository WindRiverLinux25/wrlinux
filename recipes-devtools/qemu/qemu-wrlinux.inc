#
# Copyright (C) 2022 Wind River Systems, Inc.
#

FILESEXTRAPATHS:append := ":${THISDIR}/files"

# carry over cpu affinity command line option patches
SRC_URI += " \
        file://0001-qemu-kvm-Add-options-to-pin-and-prioritize-vcpus.patch \
        file://0001-qemu-vcpu-avoid-using-ifdef-CONFIG_KVM-in-common-cod.patch \
"

PACKAGECONFIG:append:osv-wrlinux = " vhost"

# Create the symlink /usr/bin/kvm -> /usr/bin/qemu-system-${arch}
do_install:append () {
    cd ${D}${bindir}
    arch=`echo ${TARGET_ARCH} | sed 's/i[456]86/i386/' | sed 's/powerpc/ppc/'`
    ln -sf qemu-system-${arch} kvm
}
