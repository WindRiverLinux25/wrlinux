EXTRA_KERNEL_FILES =. "${THISDIR}/linux-yocto:"

#Customer Kernel CVE local patches for LTS25 week46
#LIN1025-5949 CVE-2025-38205 0001-drm-amd-display-Avoid-divide-by-zero-by-initializing.patch
#LIN1025-364  CVE-2025-22111 0002-net-Remove-RTNL-dance-for-SIOCBRADDIF-and-SIOCBRDELI.patch
#LIN1025-2327 CVE-2025-38137 0003-PCI-pwrctrl-Cancel-outstanding-rescan-work-when-unre.patch
#LIN1025-2418 CVE-2025-38203 0004-jfs-Fix-null-ptr-deref-in-jfs_ioc_trim.patch
#LIN1025-3407 CVE-2025-38621 0005-md-make-rdev_addable-usable-for-rcu-mode.patch
#LIN1025-349  CVE-2025-23131 0006-dlm-prevent-NPD-when-writing-a-positive-value-to-eve.patch
#LIN1025-348  CVE-2025-23132 0007-f2fs-quota-fix-to-avoid-warning-in-dquot_writeback_d.patch
#LIN1025-1358 CVE-2025-37906 0008-ublk-fix-race-between-io_uring_cmd_complete_in_task-.patch
#LIN1025-353  CVE-2025-22127 0009-f2fs-fix-potential-deadloop-in-prepare_compress_over.patch
#LIN1025-38   CVE-2024-52560 0010-fs-ntfs3-Mark-inode-as-bad-as-soon-as-error-detected.patch
#LIN1025-2320 CVE-2025-38132 0011-coresight-change-coresight_device-lock-type-to-raw_s.patch
#                            0012-coresight-holding-cscfg_csdev_lock-while-removing-cs.patch
#                            0013-coresight-fix-indentation-error-in-cscfg_remove_owne.patch
#LIN1025-288  CVE-2025-40325 0014-md-raid10-wait-barrier-before-returning-discard-requ.patch
#LIN1025-174  CVE-2024-58095 0015-jfs-add-check-read-only-before-txBeginAnon-call.patch
#                            0016-jfs-add-check-read-only-before-truncation-in-jfs_tru.patch
#LIN1025-175  CVE-2024-58094 0015-jfs-add-check-read-only-before-txBeginAnon-call.patch
#                            0016-jfs-add-check-read-only-before-truncation-in-jfs_tru.patch
#LIN1025-2421 CVE-2025-38206 0017-exfat-fix-double-free-in-delayed_free.patch

EXTRA_KERNEL_SRC_URI:append = " \
    file://0001-drm-amd-display-Avoid-divide-by-zero-by-initializing.patch \
    file://0002-net-Remove-RTNL-dance-for-SIOCBRADDIF-and-SIOCBRDELI.patch \
    file://0003-PCI-pwrctrl-Cancel-outstanding-rescan-work-when-unre.patch \
    file://0004-jfs-Fix-null-ptr-deref-in-jfs_ioc_trim.patch \
    file://0005-md-make-rdev_addable-usable-for-rcu-mode.patch \
    file://0006-dlm-prevent-NPD-when-writing-a-positive-value-to-eve.patch \
    file://0007-f2fs-quota-fix-to-avoid-warning-in-dquot_writeback_d.patch \
    file://0008-ublk-fix-race-between-io_uring_cmd_complete_in_task-.patch \
    file://0009-f2fs-fix-potential-deadloop-in-prepare_compress_over.patch \
    file://0010-fs-ntfs3-Mark-inode-as-bad-as-soon-as-error-detected.patch \
    file://0011-coresight-change-coresight_device-lock-type-to-raw_s.patch \
    file://0012-coresight-holding-cscfg_csdev_lock-while-removing-cs.patch \
    file://0013-coresight-fix-indentation-error-in-cscfg_remove_owne.patch \
    file://0014-md-raid10-wait-barrier-before-returning-discard-requ.patch \
    file://0015-jfs-add-check-read-only-before-txBeginAnon-call.patch \
    file://0016-jfs-add-check-read-only-before-truncation-in-jfs_tru.patch \
    file://0017-exfat-fix-double-free-in-delayed_free.patch \
"

EXTRA_KERNEL_SRC_URI += "file://0001-tools-build-make-in-target-rule-robust-against-too-l.patch"
EXTRA_KERNEL_SRC_URI:append:bcm-2xxx-rpi4 = " \
    file://0001-Revert-Revert-mmc-sdhci-Mask-spurious-interrupts.patch \
"

FILESEXTRAPATHS:prepend:osv-wrlinux := "${EXTRA_KERNEL_FILES}:"
SRC_URI:append:osv-wrlinux = " ${EXTRA_KERNEL_SRC_URI}"
