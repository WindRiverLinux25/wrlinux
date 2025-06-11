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
SRCREV_machine:kb-v6.12-standard-arm-versatile-926ejs ?= "22fa09f54f9c345541d8e68ca73106489acec177"
LINUX_VERSION:kb-v6.12-standard-arm-versatile-926ejs = "6.12.32"
SRCREV_machine:kb-v6.12-standard-base ?= "1cf1ca9467d84882daea5acf7426b214dd0a7fee"
LINUX_VERSION:kb-v6.12-standard-base = "6.12.32"
SRCREV_machine:kb-v6.12-standard-bcm-2xxx-rpi ?= "1cf1ca9467d84882daea5acf7426b214dd0a7fee"
LINUX_VERSION:kb-v6.12-standard-bcm-2xxx-rpi = "6.12.32"
SRCREV_machine:kb-v6.12-standard-beaglebone ?= "1cf1ca9467d84882daea5acf7426b214dd0a7fee"
LINUX_VERSION:kb-v6.12-standard-beaglebone = "6.12.32"
SRCREV_machine:kb-v6.12-standard-mti-malta32 ?= "bf70488668471d5d0f6128d02cc23529132a7ee4"
LINUX_VERSION:kb-v6.12-standard-mti-malta32 = "6.12.32"
SRCREV_machine:kb-v6.12-standard-mti-malta64 ?= "b35f07357970c0de8cce2f6496090f8008ffc0ab"
LINUX_VERSION:kb-v6.12-standard-mti-malta64 = "6.12.32"
SRCREV_machine:kb-v6.12-standard-nvidia-sdk-5.15-nvidia-soc ?= "53afa91bb945f03a5857d66538c9ed731d1a8ed5"
LINUX_VERSION:kb-v6.12-standard-nvidia-sdk-5.15-nvidia-soc = "6.12.32"
SRCREV_machine:kb-v6.12-standard-nxp-sdk-6.12-nxp-soc ?= "942083fedcaa47f75d85eca08d8ddb988345add5"
LINUX_VERSION:kb-v6.12-standard-nxp-sdk-6.12-nxp-soc = "6.12.32"
SRCREV_machine:kb-v6.12-standard-preempt-rt-arm-versatile-926ejs ?= "e8de143f3096d3b75fc4dd5306e796376eed99a6"
LINUX_VERSION:kb-v6.12-standard-preempt-rt-arm-versatile-926ejs = "6.12.32"
SRCREV_machine:kb-v6.12-standard-preempt-rt-base ?= "7e0aff00ea569c858bf82407f501a0bf1f678f35"
LINUX_VERSION:kb-v6.12-standard-preempt-rt-base = "6.12.32"
SRCREV_machine:kb-v6.12-standard-preempt-rt-bcm-2xxx-rpi ?= "1b22338dc0a45ca5e683d35955d0317c7a87b811"
LINUX_VERSION:kb-v6.12-standard-preempt-rt-bcm-2xxx-rpi = "6.12.32"
SRCREV_machine:kb-v6.12-standard-preempt-rt-nvidia-sdk-5.15-nvidia-soc ?= "cb8a3cb7dd56e5e3aae546bf2b04c84bf588d325"
LINUX_VERSION:kb-v6.12-standard-preempt-rt-nvidia-sdk-5.15-nvidia-soc = "6.12.32"
SRCREV_machine:kb-v6.12-standard-preempt-rt-nxp-sdk-6.12-nxp-soc ?= "e9e135718c87e93bc878d853c53426b3240d4746"
LINUX_VERSION:kb-v6.12-standard-preempt-rt-nxp-sdk-6.12-nxp-soc = "6.12.32"
SRCREV_machine:kb-v6.12-standard-preempt-rt-ti-soc ?= "a88b69f237ec83acb6f68e85c0606c5ce8196910"
LINUX_VERSION:kb-v6.12-standard-preempt-rt-ti-soc = "6.12.32"
SRCREV_machine:kb-v6.12-standard-preempt-rt-x86 ?= "88c4fcb84b915bb75018e94695dc3ef53ac15293"
LINUX_VERSION:kb-v6.12-standard-preempt-rt-x86 = "6.12.32"
SRCREV_machine:kb-v6.12-standard-preempt-rt-xlnx-soc ?= "1cb5a85df358c0d90327937051d0a94c3461e4cd"
LINUX_VERSION:kb-v6.12-standard-preempt-rt-xlnx-soc = "6.12.32"
SRCREV_machine:kb-v6.12-standard-qemuppc ?= "1cf1ca9467d84882daea5acf7426b214dd0a7fee"
LINUX_VERSION:kb-v6.12-standard-qemuppc = "6.12.32"
SRCREV_machine:kb-v6.12-standard-ti-soc ?= "924dc4f8fe11aca98f072fd35b25fc40be3acc28"
LINUX_VERSION:kb-v6.12-standard-ti-soc = "6.12.32"
SRCREV_machine:kb-v6.12-standard-tiny-arm-versatile-926ejs ?= "a50d51ce6562cf96a7c63c19044e39078181c39d"
LINUX_VERSION:kb-v6.12-standard-tiny-arm-versatile-926ejs = "6.12.32"
SRCREV_machine:kb-v6.12-standard-tiny-base ?= "1cf1ca9467d84882daea5acf7426b214dd0a7fee"
LINUX_VERSION:kb-v6.12-standard-tiny-base = "6.12.32"
SRCREV_machine:kb-v6.12-standard-tiny-x86 ?= "1cf1ca9467d84882daea5acf7426b214dd0a7fee"
LINUX_VERSION:kb-v6.12-standard-tiny-x86 = "6.12.32"
SRCREV_machine:kb-v6.12-standard-x86 ?= "1cf1ca9467d84882daea5acf7426b214dd0a7fee"
LINUX_VERSION:kb-v6.12-standard-x86 = "6.12.32"
SRCREV_machine:kb-v6.12-standard-xilinx-zynqmp ?= "1cf1ca9467d84882daea5acf7426b214dd0a7fee"
LINUX_VERSION:kb-v6.12-standard-xilinx-zynqmp = "6.12.32"
SRCREV_machine:kb-v6.12-standard-xlnx-soc ?= "4c69e5012bdc92dfa04f1a9b67a82ef672392b6f"
LINUX_VERSION:kb-v6.12-standard-xlnx-soc = "6.12.32"

# yocto-kernel-cache entries
KERNEL_CACHE_BRANCH_6.12 = "yocto-6.12"
SRCREV_meta_6.12 = "05bb764f1cf3f7123247c63b7c3fe080ebf509cb"
