# Add profiling optimization type
PROFILING_OPTIMIZATION = "${FULL_OPTIMIZATION} -fno-omit-frame-pointer -fvisibility=default"
SELECTED_OPTIMIZATION[vardeps] += "PROFILING_OPTIMIZATION"

# Some packages have problems with PROFILING_OPTIMIZATION
#
# fix linking/relocating error
PROFILING_OPTIMIZATION:remove:pn-llvm:powerpc = "-fno-omit-frame-pointer"
# fix error: r7 cannot be used in asm here
PROFILING_OPTIMIZATION:remove:pn-pulseaudio:arm = "-fno-omit-frame-pointer"
# gcc-sanitizers makes extensive use of hidden visibility and frame pointer omission.
# Trying to override that can cause build failures.
PROFILING_OPTIMIZATION:pn-gcc-sanitizers = "${FULL_OPTIMIZATION}"
# Fix traps: python[550] trap invalid opcode ip:b7f80f00 sp:bfb09a10 error:0 in ld-2.30.so[b7f7b000+1c000]
PROFILING_OPTIMIZATION:remove:pn-glibc:x86 = "-fno-omit-frame-pointer"
# Fix | stress-enosys.c: In function 'exercise_syscall':
#     | stress-enosys.c:230:1: error: bp cannot be used in 'asm' here
#     |   230 | }
PROFILING_OPTIMIZATION:remove:pn-stress-ng:x86-64 = "-fno-omit-frame-pointer"
PROFILING_OPTIMIZATION:remove:pn-stress-ng:x86 = "-fno-omit-frame-pointer"

# Set for SPDX 3
SPDX_AUTHORS_openembedded_comment ??= "${DISTRO_NAME} ${DISTRO_VERSION}"
SPDX_PACKAGE_VERSION ?= "${EXTENDPKGV}"

# PACKAGECONFIG settings for WRLinux
include conf/distro/include/wrlinux-packageconfigs.inc

# MIRRORS are used only if we don't have a local copy, and the stated upstream
# is no longer available.
MIRRORS =+ "\
bzr://.*/.*      http://downloads.yoctoproject.org/mirror/sources/ \n \
cvs://.*/.*      http://downloads.yoctoproject.org/mirror/sources/ \n \
git://.*/.*      http://downloads.yoctoproject.org/mirror/sources/ \n \
gitsm://.*/.*    http://downloads.yoctoproject.org/mirror/sources/ \n \
hg://.*/.*       http://downloads.yoctoproject.org/mirror/sources/ \n \
osc://.*/.*      http://downloads.yoctoproject.org/mirror/sources/ \n \
p4://.*/.*       http://downloads.yoctoproject.org/mirror/sources/ \n \
svn://.*/.*      http://downloads.yoctoproject.org/mirror/sources/ \n \
ftp://.*/.*      http://downloads.yoctoproject.org/mirror/sources/ \n \
http://.*/.*     http://downloads.yoctoproject.org/mirror/sources/ \n \
https://.*/.*    http://downloads.yoctoproject.org/mirror/sources/ \n"

# dnsmasq and named (provided by bind) use the same default port 53:
# | dnsmasq: failed to create listening socket for port 53: Address already in use
# So disable the service by default, and if the user want to use both of them,
# it need to be set to a different port in dnsmasq.conf before starting the service.
INITSCRIPT_PARAMS:pn-dnsmasq = "stop 20 0 1 6 ."
SYSTEMD_AUTO_ENABLE:pn-dnsmasq = "disable"

# Exclude download layers from eSDK.
SDK_LAYERS_EXCLUDE_PATTERN ?= ".*-dl$ .*-dl-[0-9.]+$"

# do_kernel_version_sanity_check in oe-core checks if the defined version in
# metadata(LINUX_VERSION) matches the version written in the source code. For
# release branches we have Jenkins to take care of the version updating. For
# CI/CD branch we aim to use the latest source and directly use Yocto kernel
# source code which frequently gets updated. But oe-core does not tightly follow
# the latest version. We don't necessarily frequently manually bump up the
# version.
KERNEL_VERSION_SANITY_SKIP = "1"

require conf/distro/include/security_flags_wrs.inc
