#
# This file is generated based on:
#     linux-yocto-6.12
#     yocto-kernel-cache
#
# Any manual changes will be overwritten.
#
# This will cause SRCREV_machine:kb-<KBRANCH> take priority over SRCREV_machine:<machine>
MACHINEOVERRIDES .= ":kb-${@oe.utils.conditional('PREFERRED_PROVIDER_virtual/kernel', 'linux-yocto-dev', 'dev-', '', d)}${@d.getVar('KBRANCH', True).replace("/", "-")}"

# linux-yocto-6.12 entries

# linux-yocto-6.12 branch entries
SRCREV_machine:kb-master ?= "0bcda530593bba114c23c9e6fa9f268062975390"
LINUX_VERSION:kb-master = "6.12"
SRCREV_machine:kb-v6.12-base ?= "df3f6d10f353de274cc7c87f52dba5d26f185393"
LINUX_VERSION:kb-v6.12-base = "6.12.31"
SRCREV_machine:kb-v6.12-standard-arm-versatile-926ejs ?= "4260a7bd706072e6bec438cdc29f44845d380b21"
LINUX_VERSION:kb-v6.12-standard-arm-versatile-926ejs = "6.12.31"
SRCREV_machine:kb-v6.12-standard-base ?= "fee8195f8412ff8f1bfc50ba86cdb8f20de22750"
LINUX_VERSION:kb-v6.12-standard-base = "6.12.31"
SRCREV_machine:kb-v6.12-standard-bcm-2xxx-rpi ?= "fee8195f8412ff8f1bfc50ba86cdb8f20de22750"
LINUX_VERSION:kb-v6.12-standard-bcm-2xxx-rpi = "6.12.31"
SRCREV_machine:kb-v6.12-standard-beaglebone ?= "fee8195f8412ff8f1bfc50ba86cdb8f20de22750"
LINUX_VERSION:kb-v6.12-standard-beaglebone = "6.12.31"
SRCREV_machine:kb-v6.12-standard-mti-malta32 ?= "681fad27d382f2e0eb53d1b46f9d35aa2332248f"
LINUX_VERSION:kb-v6.12-standard-mti-malta32 = "6.12.31"
SRCREV_machine:kb-v6.12-standard-mti-malta64 ?= "c32033ad8eac09b074c44a42e7d34d398df9d172"
LINUX_VERSION:kb-v6.12-standard-mti-malta64 = "6.12.31"
SRCREV_machine:kb-v6.12-standard-nvidia-sdk-5.15-nvidia-soc ?= "95e974d94f302f9da851bd81477daa14a38c8a32"
LINUX_VERSION:kb-v6.12-standard-nvidia-sdk-5.15-nvidia-soc = "6.12.31"
SRCREV_machine:kb-v6.12-standard-nxp-sdk-6.12-nxp-soc ?= "47f6675359efa705f4c1591bf2d44b2eef0ec5cb"
LINUX_VERSION:kb-v6.12-standard-nxp-sdk-6.12-nxp-soc = "6.12.31"
SRCREV_machine:kb-v6.12-standard-preempt-rt-arm-versatile-926ejs ?= "bf14a5ee32ae335213e607f7d89b831884507bd6"
LINUX_VERSION:kb-v6.12-standard-preempt-rt-arm-versatile-926ejs = "6.12.31"
SRCREV_machine:kb-v6.12-standard-preempt-rt-base ?= "4127c6137af28c2c91ec79acee60fe4d4d70db9b"
LINUX_VERSION:kb-v6.12-standard-preempt-rt-base = "6.12.31"
SRCREV_machine:kb-v6.12-standard-preempt-rt-bcm-2xxx-rpi ?= "6fe81475a4e471730cbca0386849513343281b5e"
LINUX_VERSION:kb-v6.12-standard-preempt-rt-bcm-2xxx-rpi = "6.12.31"
SRCREV_machine:kb-v6.12-standard-preempt-rt-nvidia-sdk-5.15-nvidia-soc ?= "230c703fb55df136040dc34365d382d0fe09bacf"
LINUX_VERSION:kb-v6.12-standard-preempt-rt-nvidia-sdk-5.15-nvidia-soc = "6.12.31"
SRCREV_machine:kb-v6.12-standard-preempt-rt-nxp-sdk-6.12-nxp-soc ?= "69bc9bf0944fc180f5ee6c1629fb285d05391bc4"
LINUX_VERSION:kb-v6.12-standard-preempt-rt-nxp-sdk-6.12-nxp-soc = "6.12.31"
SRCREV_machine:kb-v6.12-standard-preempt-rt-x86 ?= "dcaf212deeafa0dcde155c1cd59be952c1c7c989"
LINUX_VERSION:kb-v6.12-standard-preempt-rt-x86 = "6.12.31"
SRCREV_machine:kb-v6.12-standard-qemuppc ?= "fee8195f8412ff8f1bfc50ba86cdb8f20de22750"
LINUX_VERSION:kb-v6.12-standard-qemuppc = "6.12.31"
SRCREV_machine:kb-v6.12-standard-tiny-arm-versatile-926ejs ?= "130a3241d575f064f9eab5cff7f83947f0beb0bf"
LINUX_VERSION:kb-v6.12-standard-tiny-arm-versatile-926ejs = "6.12.31"
SRCREV_machine:kb-v6.12-standard-tiny-base ?= "fee8195f8412ff8f1bfc50ba86cdb8f20de22750"
LINUX_VERSION:kb-v6.12-standard-tiny-base = "6.12.31"
SRCREV_machine:kb-v6.12-standard-tiny-x86 ?= "fee8195f8412ff8f1bfc50ba86cdb8f20de22750"
LINUX_VERSION:kb-v6.12-standard-tiny-x86 = "6.12.31"
SRCREV_machine:kb-v6.12-standard-x86 ?= "fee8195f8412ff8f1bfc50ba86cdb8f20de22750"
LINUX_VERSION:kb-v6.12-standard-x86 = "6.12.31"
SRCREV_machine:kb-v6.12-standard-xilinx-zynqmp ?= "fee8195f8412ff8f1bfc50ba86cdb8f20de22750"
LINUX_VERSION:kb-v6.12-standard-xilinx-zynqmp = "6.12.31"

# yocto-kernel-cache entries
KERNEL_CACHE_BRANCH_6.12 = "yocto-6.12"
SRCREV_meta_6.12 = "f2f3b6cbd91743920e2cb55998c53326855b2e9c"
