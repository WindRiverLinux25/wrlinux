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
SRCREV_machine:kb-v6.12-base ?= "e0e2f78243385e7188a57fcfceb6a19f723f1dff"
LINUX_VERSION:kb-v6.12-base = "6.12.30"
SRCREV_machine:kb-v6.12-standard-arm-versatile-926ejs ?= "5c1cc01b780f83de6f9c0bacf45ffa2de68be95c"
LINUX_VERSION:kb-v6.12-standard-arm-versatile-926ejs = "6.12.30"
SRCREV_machine:kb-v6.12-standard-base ?= "0898369ce44f92eba60ae9bf0013bc4338ce840e"
LINUX_VERSION:kb-v6.12-standard-base = "6.12.30"
SRCREV_machine:kb-v6.12-standard-bcm-2xxx-rpi ?= "0898369ce44f92eba60ae9bf0013bc4338ce840e"
LINUX_VERSION:kb-v6.12-standard-bcm-2xxx-rpi = "6.12.30"
SRCREV_machine:kb-v6.12-standard-beaglebone ?= "0898369ce44f92eba60ae9bf0013bc4338ce840e"
LINUX_VERSION:kb-v6.12-standard-beaglebone = "6.12.30"
SRCREV_machine:kb-v6.12-standard-mti-malta32 ?= "87d7d289ec3d56a1bd1d7a7c7cb46af8cf6c0f27"
LINUX_VERSION:kb-v6.12-standard-mti-malta32 = "6.12.30"
SRCREV_machine:kb-v6.12-standard-mti-malta64 ?= "98a85ed93bd5eaefe30c4aa3f7c15549be2bd032"
LINUX_VERSION:kb-v6.12-standard-mti-malta64 = "6.12.30"
SRCREV_machine:kb-v6.12-standard-nvidia-sdk-5.15-nvidia-soc ?= "9f109da4d2142db25fbcf583d6ec87f8fd7505df"
LINUX_VERSION:kb-v6.12-standard-nvidia-sdk-5.15-nvidia-soc = "6.12.30"
SRCREV_machine:kb-v6.12-standard-nxp-sdk-6.12-nxp-soc ?= "107120d0de6ce0ba0a3658574a2723c83cee4b3f"
LINUX_VERSION:kb-v6.12-standard-nxp-sdk-6.12-nxp-soc = "6.12.30"
SRCREV_machine:kb-v6.12-standard-preempt-rt-arm-versatile-926ejs ?= "821b488cebc6a3ef5e69fdff96b915ca37af33a2"
LINUX_VERSION:kb-v6.12-standard-preempt-rt-arm-versatile-926ejs = "6.12.30"
SRCREV_machine:kb-v6.12-standard-preempt-rt-base ?= "3d3d56a846c993611859096016322dccea1317cd"
LINUX_VERSION:kb-v6.12-standard-preempt-rt-base = "6.12.30"
SRCREV_machine:kb-v6.12-standard-preempt-rt-bcm-2xxx-rpi ?= "b480cf08668916fabf9fe18eabee637fc2bd51ef"
LINUX_VERSION:kb-v6.12-standard-preempt-rt-bcm-2xxx-rpi = "6.12.30"
SRCREV_machine:kb-v6.12-standard-preempt-rt-nvidia-sdk-5.15-nvidia-soc ?= "3e563d344b1611112e20adb4b4634ab75f2ae430"
LINUX_VERSION:kb-v6.12-standard-preempt-rt-nvidia-sdk-5.15-nvidia-soc = "6.12.30"
SRCREV_machine:kb-v6.12-standard-preempt-rt-nxp-sdk-6.12-nxp-soc ?= "0fb6f73f35741dfe10d6b561e0efd0d53a3cb0e2"
LINUX_VERSION:kb-v6.12-standard-preempt-rt-nxp-sdk-6.12-nxp-soc = "6.12.30"
SRCREV_machine:kb-v6.12-standard-preempt-rt-x86 ?= "b1b97590389ab90c249afe412ba5c8873a62733a"
LINUX_VERSION:kb-v6.12-standard-preempt-rt-x86 = "6.12.30"
SRCREV_machine:kb-v6.12-standard-qemuppc ?= "0898369ce44f92eba60ae9bf0013bc4338ce840e"
LINUX_VERSION:kb-v6.12-standard-qemuppc = "6.12.30"
SRCREV_machine:kb-v6.12-standard-tiny-arm-versatile-926ejs ?= "5c5147a4ba4e803c3fc0c6ae4ea2d4a2f4e8f52f"
LINUX_VERSION:kb-v6.12-standard-tiny-arm-versatile-926ejs = "6.12.30"
SRCREV_machine:kb-v6.12-standard-tiny-base ?= "0898369ce44f92eba60ae9bf0013bc4338ce840e"
LINUX_VERSION:kb-v6.12-standard-tiny-base = "6.12.30"
SRCREV_machine:kb-v6.12-standard-tiny-x86 ?= "0898369ce44f92eba60ae9bf0013bc4338ce840e"
LINUX_VERSION:kb-v6.12-standard-tiny-x86 = "6.12.30"
SRCREV_machine:kb-v6.12-standard-x86 ?= "0898369ce44f92eba60ae9bf0013bc4338ce840e"
LINUX_VERSION:kb-v6.12-standard-x86 = "6.12.30"
SRCREV_machine:kb-v6.12-standard-xilinx-zynqmp ?= "0898369ce44f92eba60ae9bf0013bc4338ce840e"
LINUX_VERSION:kb-v6.12-standard-xilinx-zynqmp = "6.12.30"

# yocto-kernel-cache entries
KERNEL_CACHE_BRANCH_6.12 = "yocto-6.12"
SRCREV_meta_6.12 = "3a5fec1707626251d69b7548f024856d838cc7db"
