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
SRCREV_machine:kb-v6.12-base ?= "ba9210b8c96355a16b78e1b890dce78f284d6f31"
LINUX_VERSION:kb-v6.12-base = "6.12.32"
SRCREV_machine:kb-v6.12-standard-arm-versatile-926ejs ?= "be3c08ed343992d62710e7c6dec59b52ab1ed9a0"
LINUX_VERSION:kb-v6.12-standard-arm-versatile-926ejs = "6.12.32"
SRCREV_machine:kb-v6.12-standard-base ?= "f724ffca3fef3541b4be9f30f0a3261674c60e13"
LINUX_VERSION:kb-v6.12-standard-base = "6.12.32"
SRCREV_machine:kb-v6.12-standard-bcm-2xxx-rpi ?= "f724ffca3fef3541b4be9f30f0a3261674c60e13"
LINUX_VERSION:kb-v6.12-standard-bcm-2xxx-rpi = "6.12.32"
SRCREV_machine:kb-v6.12-standard-beaglebone ?= "f724ffca3fef3541b4be9f30f0a3261674c60e13"
LINUX_VERSION:kb-v6.12-standard-beaglebone = "6.12.32"
SRCREV_machine:kb-v6.12-standard-mti-malta32 ?= "caf8b2498f27e7cf8d2ea23a823059c53d622567"
LINUX_VERSION:kb-v6.12-standard-mti-malta32 = "6.12.32"
SRCREV_machine:kb-v6.12-standard-mti-malta64 ?= "f785750b2d7a06b2b19e69cc321665cb5f2d8e51"
LINUX_VERSION:kb-v6.12-standard-mti-malta64 = "6.12.32"
SRCREV_machine:kb-v6.12-standard-nvidia-sdk-5.15-nvidia-soc ?= "5b22346d4ce17d3fc48bdde3d34555c2e9e92d0e"
LINUX_VERSION:kb-v6.12-standard-nvidia-sdk-5.15-nvidia-soc = "6.12.32"
SRCREV_machine:kb-v6.12-standard-nxp-sdk-6.12-nxp-soc ?= "f33744258766192c1c898f269cdbcff6b2806935"
LINUX_VERSION:kb-v6.12-standard-nxp-sdk-6.12-nxp-soc = "6.12.32"
SRCREV_machine:kb-v6.12-standard-preempt-rt-arm-versatile-926ejs ?= "92732b58fef4a043d2ce64392a68ba77a42c325e"
LINUX_VERSION:kb-v6.12-standard-preempt-rt-arm-versatile-926ejs = "6.12.32"
SRCREV_machine:kb-v6.12-standard-preempt-rt-base ?= "b1b3b3bd2dca380a849e9c593a1186d4f5f6b57d"
LINUX_VERSION:kb-v6.12-standard-preempt-rt-base = "6.12.32"
SRCREV_machine:kb-v6.12-standard-preempt-rt-bcm-2xxx-rpi ?= "0267ea8d8acf5ae5e246b48d38b83bff17f47cae"
LINUX_VERSION:kb-v6.12-standard-preempt-rt-bcm-2xxx-rpi = "6.12.32"
SRCREV_machine:kb-v6.12-standard-preempt-rt-nvidia-sdk-5.15-nvidia-soc ?= "e5155412f860d7a4e603037a4133863d84883ac1"
LINUX_VERSION:kb-v6.12-standard-preempt-rt-nvidia-sdk-5.15-nvidia-soc = "6.12.32"
SRCREV_machine:kb-v6.12-standard-preempt-rt-nxp-sdk-6.12-nxp-soc ?= "dc0f5ae18bc0167e6c74257f241581e6c7c13dd8"
LINUX_VERSION:kb-v6.12-standard-preempt-rt-nxp-sdk-6.12-nxp-soc = "6.12.32"
SRCREV_machine:kb-v6.12-standard-preempt-rt-x86 ?= "f7cdd593b4999d25398d8ec2c75f2bbf07a66f5a"
LINUX_VERSION:kb-v6.12-standard-preempt-rt-x86 = "6.12.32"
SRCREV_machine:kb-v6.12-standard-qemuppc ?= "f724ffca3fef3541b4be9f30f0a3261674c60e13"
LINUX_VERSION:kb-v6.12-standard-qemuppc = "6.12.32"
SRCREV_machine:kb-v6.12-standard-tiny-arm-versatile-926ejs ?= "21f0280800dec7e2e7feb5d81af006488b68732f"
LINUX_VERSION:kb-v6.12-standard-tiny-arm-versatile-926ejs = "6.12.32"
SRCREV_machine:kb-v6.12-standard-tiny-base ?= "f724ffca3fef3541b4be9f30f0a3261674c60e13"
LINUX_VERSION:kb-v6.12-standard-tiny-base = "6.12.32"
SRCREV_machine:kb-v6.12-standard-tiny-x86 ?= "f724ffca3fef3541b4be9f30f0a3261674c60e13"
LINUX_VERSION:kb-v6.12-standard-tiny-x86 = "6.12.32"
SRCREV_machine:kb-v6.12-standard-x86 ?= "f724ffca3fef3541b4be9f30f0a3261674c60e13"
LINUX_VERSION:kb-v6.12-standard-x86 = "6.12.32"
SRCREV_machine:kb-v6.12-standard-xilinx-zynqmp ?= "f724ffca3fef3541b4be9f30f0a3261674c60e13"
LINUX_VERSION:kb-v6.12-standard-xilinx-zynqmp = "6.12.32"

# yocto-kernel-cache entries
KERNEL_CACHE_BRANCH_6.12 = "yocto-6.12"
SRCREV_meta_6.12 = "6ce336f711be8ab3b814422f869f5c5dc64bb1ed"
