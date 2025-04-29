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
SRCREV_machine:kb-v6.12-base ?= "ef4999852d307d38cfdecd91ed6892cc03beb9b8"
LINUX_VERSION:kb-v6.12-base = "6.12.25"
SRCREV_machine:kb-v6.12-standard-arm-versatile-926ejs ?= "ab61ca00dc8c8d6992d25112dadeed88b8c48bdc"
LINUX_VERSION:kb-v6.12-standard-arm-versatile-926ejs = "6.12.25"
SRCREV_machine:kb-v6.12-standard-base ?= "8bdb46d18b39209344e65cd7ee24d1fa451397d5"
LINUX_VERSION:kb-v6.12-standard-base = "6.12.25"
SRCREV_machine:kb-v6.12-standard-bcm-2xxx-rpi ?= "8bdb46d18b39209344e65cd7ee24d1fa451397d5"
LINUX_VERSION:kb-v6.12-standard-bcm-2xxx-rpi = "6.12.25"
SRCREV_machine:kb-v6.12-standard-beaglebone ?= "8bdb46d18b39209344e65cd7ee24d1fa451397d5"
LINUX_VERSION:kb-v6.12-standard-beaglebone = "6.12.25"
SRCREV_machine:kb-v6.12-standard-mti-malta32 ?= "9d52a1ea29e175681780b615541b0af66f9d0d55"
LINUX_VERSION:kb-v6.12-standard-mti-malta32 = "6.12.25"
SRCREV_machine:kb-v6.12-standard-mti-malta64 ?= "54af295ab3ca402812576c8425d92dcabe9f0b0d"
LINUX_VERSION:kb-v6.12-standard-mti-malta64 = "6.12.25"
SRCREV_machine:kb-v6.12-standard-nxp-sdk-6.12-nxp-soc ?= "9572af3ca4757ae4ad1544f976bceb85e938c950"
LINUX_VERSION:kb-v6.12-standard-nxp-sdk-6.12-nxp-soc = "6.12.25"
SRCREV_machine:kb-v6.12-standard-preempt-rt-arm-versatile-926ejs ?= "6446b747143aa1eba3a187f8b38288d2e871649b"
LINUX_VERSION:kb-v6.12-standard-preempt-rt-arm-versatile-926ejs = "6.12.25"
SRCREV_machine:kb-v6.12-standard-preempt-rt-base ?= "a20f2b5c8760fc32bd7137fbd952f7f3f810ae26"
LINUX_VERSION:kb-v6.12-standard-preempt-rt-base = "6.12.25"
SRCREV_machine:kb-v6.12-standard-preempt-rt-bcm-2xxx-rpi ?= "80207210347e483071c90acddbe9c9e6ddfc3db0"
LINUX_VERSION:kb-v6.12-standard-preempt-rt-bcm-2xxx-rpi = "6.12.25"
SRCREV_machine:kb-v6.12-standard-preempt-rt-nxp-sdk-6.12-nxp-soc ?= "5045cd91d609ea6d4bc381f9bedd5f5d7d16d30a"
LINUX_VERSION:kb-v6.12-standard-preempt-rt-nxp-sdk-6.12-nxp-soc = "6.12.25"
SRCREV_machine:kb-v6.12-standard-preempt-rt-x86 ?= "a8b790022d48056205ab5344ef540f86a02893dd"
LINUX_VERSION:kb-v6.12-standard-preempt-rt-x86 = "6.12.25"
SRCREV_machine:kb-v6.12-standard-qemuppc ?= "8bdb46d18b39209344e65cd7ee24d1fa451397d5"
LINUX_VERSION:kb-v6.12-standard-qemuppc = "6.12.25"
SRCREV_machine:kb-v6.12-standard-tiny-arm-versatile-926ejs ?= "bcb9467b69cc283da9fa1eaef45af18ea06bd7a0"
LINUX_VERSION:kb-v6.12-standard-tiny-arm-versatile-926ejs = "6.12.25"
SRCREV_machine:kb-v6.12-standard-tiny-base ?= "8bdb46d18b39209344e65cd7ee24d1fa451397d5"
LINUX_VERSION:kb-v6.12-standard-tiny-base = "6.12.25"
SRCREV_machine:kb-v6.12-standard-tiny-x86 ?= "8bdb46d18b39209344e65cd7ee24d1fa451397d5"
LINUX_VERSION:kb-v6.12-standard-tiny-x86 = "6.12.25"
SRCREV_machine:kb-v6.12-standard-x86 ?= "8bdb46d18b39209344e65cd7ee24d1fa451397d5"
LINUX_VERSION:kb-v6.12-standard-x86 = "6.12.25"
SRCREV_machine:kb-v6.12-standard-xilinx-zynqmp ?= "8bdb46d18b39209344e65cd7ee24d1fa451397d5"
LINUX_VERSION:kb-v6.12-standard-xilinx-zynqmp = "6.12.25"

# yocto-kernel-cache entries
KERNEL_CACHE_BRANCH_6.12 = "yocto-6.12"
SRCREV_meta_6.12 = "47b69a68c57e1c58e83732fe46849190d2a00cbf"
