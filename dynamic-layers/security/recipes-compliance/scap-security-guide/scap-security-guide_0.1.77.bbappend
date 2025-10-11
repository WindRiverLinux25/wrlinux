FILESEXTRAPATHS:prepend := "${THISDIR}/files:"

SRC_URI += "file://0001-Add-product-WRLinux-LTS25.patch \
            file://0002-Set-correct-package-names-for-wrlinuxlts25.patch \
            file://0003-Enable-systemd-service_enable-disable.patch \
            file://0004-Set-grub2-boot-path-for-wrlinux.patch \
            file://0005-Set-selinux-policy-type-for-wrlinux.patch \
            file://0006-Replace-aide-with-samhain.patch \
            file://0007-Enable-openssh-rules-for-wrlinux.patch \
            file://0008-Enable-sysctl-rules-for-wrlinux.patch \
            file://0009-Enable-snmpd_not_default_password-rule.patch \
            file://0010-Enable-kernel_module_disabled-rule.patch \
            file://0011-Fix-path-of-pidof-command-in-chronyd_or_ntpd_set_max.patch \
            file://0012-Set-correct-package-name-for-ip6tables.patch \
            file://0013-Enable-sysctl_kernel_ipv6_disable-rule.patch \
            file://0014-Enable-audit-related-rules.patch \
            file://0015-Enable-banner_etc_issue-rule.patch \
            file://0016-Enable-set_password_hashing_algorithm-rules.patch \
            file://0017-Enable-accounts_password_set_max_life_existing-rule.patch \
            file://0018-Enable-rsyslog_remote_loghost-rule.patch \
            file://0019-Enable-rsyslog_cron_logging-rule.patch \
            file://0020-Enable-display_login_attempts-rule.patch \
            file://0021-Enable-account_disable_post_pw_expiration-rule.patch \
            file://0022-Enable-accounts_logon_fail_delay-rule.patch \
            file://0023-Enable-accounts_max_concurrent_login_sessions-rule.patch \
            file://0024-Enable-password_quality-rules.patch \
            file://0025-Fix-accounts_password_pam_unix_remember-rule.patch \
            file://0026-Fix-accounts_passwords_pam_faillock_deny-rule.patch \
            file://0027-Fix-accounts_passwords_pam_faillock_deny_root-rule.patch \
            file://0028-Fix-accounts_passwords_pam_faillock_interval-rule.patch \
            file://0029-Fix-accounts_passwords_pam_faillock_unlock_time-rule.patch \
            file://0030-Enable-sssd-related-rules.patch \
            file://0031-Enable-grub2_uefi_password-rule.patch \
            file://0032-Enable-rpm_verification-rules.patch \
            file://0033-Enable-require_singleuser_auth-rule.patch \
           "

EXTRA_OECMAKE += "-DSSG_PRODUCT_DEFAULT=OFF \
                  -DSSG_PRODUCT_OPENEMBEDDED=OFF \
                  -DSSG_PRODUCT_WRLINUXLTS25=ON \
                  "
