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
SRCREV_machine:kb-v6.12-base ?= "5be5dbf91ef3c8643d2a3698d557a52059702487"
LINUX_VERSION:kb-v6.12-base = "6.12.29"
SRCREV_machine:kb-v6.12-standard-arm-versatile-926ejs ?= "556bd3efe644334440f7c2be6df21a5d05d9e471"
LINUX_VERSION:kb-v6.12-standard-arm-versatile-926ejs = "6.12.29"
SRCREV_machine:kb-v6.12-standard-base ?= "e4b00bee45a4432a5739542e2b50def9a63ba6d0"
LINUX_VERSION:kb-v6.12-standard-base = "6.12.29"
SRCREV_machine:kb-v6.12-standard-bcm-2xxx-rpi ?= "e4b00bee45a4432a5739542e2b50def9a63ba6d0"
LINUX_VERSION:kb-v6.12-standard-bcm-2xxx-rpi = "6.12.29"
SRCREV_machine:kb-v6.12-standard-beaglebone ?= "e4b00bee45a4432a5739542e2b50def9a63ba6d0"
LINUX_VERSION:kb-v6.12-standard-beaglebone = "6.12.29"
SRCREV_machine:kb-v6.12-standard-mti-malta32 ?= "93b73e8b0f1d2d23499ece2050e55a69057aec5a"
LINUX_VERSION:kb-v6.12-standard-mti-malta32 = "6.12.29"
SRCREV_machine:kb-v6.12-standard-mti-malta64 ?= "e2f38ec1df747da895699dcb9955606e1a8d60da"
LINUX_VERSION:kb-v6.12-standard-mti-malta64 = "6.12.29"
SRCREV_machine:kb-v6.12-standard-nxp-sdk-6.12-nxp-soc ?= "07d1f96baac23be335bba4a956f3a0ae535e17f6"
LINUX_VERSION:kb-v6.12-standard-nxp-sdk-6.12-nxp-soc = "6.12.29"
SRCREV_machine:kb-v6.12-standard-preempt-rt-arm-versatile-926ejs ?= "1a80b7a87e238e3f1469d34b7a878824c176c213"
LINUX_VERSION:kb-v6.12-standard-preempt-rt-arm-versatile-926ejs = "6.12.29"
SRCREV_machine:kb-v6.12-standard-preempt-rt-base ?= "9ee7ecfcabe12ffae693f11c83d8cf6d8181f12a"
LINUX_VERSION:kb-v6.12-standard-preempt-rt-base = "6.12.29"
SRCREV_machine:kb-v6.12-standard-preempt-rt-bcm-2xxx-rpi ?= "10fc37ecd20cb5e474e4123faa3a9a82e0945813"
LINUX_VERSION:kb-v6.12-standard-preempt-rt-bcm-2xxx-rpi = "6.12.29"
SRCREV_machine:kb-v6.12-standard-preempt-rt-nxp-sdk-6.12-nxp-soc ?= "b7326c2493142729cc061f6664480227c76b3477"
LINUX_VERSION:kb-v6.12-standard-preempt-rt-nxp-sdk-6.12-nxp-soc = "6.12.29"
SRCREV_machine:kb-v6.12-standard-preempt-rt-x86 ?= "bcb33d665b335ae5ace01e24d7e5f607d90aa115"
LINUX_VERSION:kb-v6.12-standard-preempt-rt-x86 = "6.12.29"
SRCREV_machine:kb-v6.12-standard-qemuppc ?= "e4b00bee45a4432a5739542e2b50def9a63ba6d0"
LINUX_VERSION:kb-v6.12-standard-qemuppc = "6.12.29"
SRCREV_machine:kb-v6.12-standard-tiny-arm-versatile-926ejs ?= "b8b8abc77065c6c9ba93f28eec2eb4d0f95149bf"
LINUX_VERSION:kb-v6.12-standard-tiny-arm-versatile-926ejs = "6.12.29"
SRCREV_machine:kb-v6.12-standard-tiny-base ?= "e4b00bee45a4432a5739542e2b50def9a63ba6d0"
LINUX_VERSION:kb-v6.12-standard-tiny-base = "6.12.29"
SRCREV_machine:kb-v6.12-standard-tiny-x86 ?= "e4b00bee45a4432a5739542e2b50def9a63ba6d0"
LINUX_VERSION:kb-v6.12-standard-tiny-x86 = "6.12.29"
SRCREV_machine:kb-v6.12-standard-x86 ?= "e4b00bee45a4432a5739542e2b50def9a63ba6d0"
LINUX_VERSION:kb-v6.12-standard-x86 = "6.12.29"
SRCREV_machine:kb-v6.12-standard-xilinx-zynqmp ?= "e4b00bee45a4432a5739542e2b50def9a63ba6d0"
LINUX_VERSION:kb-v6.12-standard-xilinx-zynqmp = "6.12.29"

# yocto-kernel-cache entries
KERNEL_CACHE_BRANCH_6.12 = "yocto-6.12"
SRCREV_meta_6.12 = "020a66c734ee618ed2b25a89102fd8de2ef98f9b"
