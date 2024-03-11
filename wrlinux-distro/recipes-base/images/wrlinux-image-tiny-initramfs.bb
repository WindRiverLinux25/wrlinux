require ${COREBASE}/meta/recipes-core/images/core-image-tiny-initramfs.bb

export IMAGE_BASENAME = "wrlinux-image-tiny-initramfs"

QB_DEFAULT_FSTYPE = "cpio.gz"

# explictly install os-release
PACKAGE_INSTALL += "os-release"

inherit wrlinux-image
