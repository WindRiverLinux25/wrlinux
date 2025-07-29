EXTRA_KERNEL_FILES ?= "${THISDIR}/linux-yocto"
EXTRA_KERNEL_SRC_URI ?= "file://0001-tools-build-make-in-target-rule-robust-against-too-l.patch"
EXTRA_KERNEL_SRC_URI:append:bcm-2xxx-rpi4 = " \
    file://0001-Revert-Revert-mmc-sdhci-Mask-spurious-interrupts.patch \
"

FILESEXTRAPATHS:prepend:osv-wrlinux := "${EXTRA_KERNEL_FILES}:"
SRC_URI:append:osv-wrlinux = " ${EXTRA_KERNEL_SRC_URI}"
