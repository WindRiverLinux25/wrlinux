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
SRCREV_machine:kb-v6.12-base ?= "b801eaa96a5a2f2a8fe0b5982ffe4a1fba3c1e93"
LINUX_VERSION:kb-v6.12-base = "6.12.27"
SRCREV_machine:kb-v6.12-standard-arm-versatile-926ejs ?= "e1aec462165a127bd7a549f77e8e955c6d38ba79"
LINUX_VERSION:kb-v6.12-standard-arm-versatile-926ejs = "6.12.27"
SRCREV_machine:kb-v6.12-standard-base ?= "5b22e7aef539a991b75fa45101cbc02051327cb6"
LINUX_VERSION:kb-v6.12-standard-base = "6.12.27"
SRCREV_machine:kb-v6.12-standard-bcm-2xxx-rpi ?= "5b22e7aef539a991b75fa45101cbc02051327cb6"
LINUX_VERSION:kb-v6.12-standard-bcm-2xxx-rpi = "6.12.27"
SRCREV_machine:kb-v6.12-standard-beaglebone ?= "5b22e7aef539a991b75fa45101cbc02051327cb6"
LINUX_VERSION:kb-v6.12-standard-beaglebone = "6.12.27"
SRCREV_machine:kb-v6.12-standard-mti-malta32 ?= "c8eb4283f60d76e0f0e3db984bb09e1309550604"
LINUX_VERSION:kb-v6.12-standard-mti-malta32 = "6.12.27"
SRCREV_machine:kb-v6.12-standard-mti-malta64 ?= "8e88d1714f7f56efc4650cf84b86845d44c01eb1"
LINUX_VERSION:kb-v6.12-standard-mti-malta64 = "6.12.27"
SRCREV_machine:kb-v6.12-standard-nxp-sdk-6.12-nxp-soc ?= "9d99441eb15fac794679e664397da6bb1bced596"
LINUX_VERSION:kb-v6.12-standard-nxp-sdk-6.12-nxp-soc = "6.12.27"
SRCREV_machine:kb-v6.12-standard-preempt-rt-arm-versatile-926ejs ?= "e7a51759a598ec63b6d6e5772566891b9693f9af"
LINUX_VERSION:kb-v6.12-standard-preempt-rt-arm-versatile-926ejs = "6.12.27"
SRCREV_machine:kb-v6.12-standard-preempt-rt-base ?= "28fcf1f308c59515410f6a0d0bc3278d5296a3c1"
LINUX_VERSION:kb-v6.12-standard-preempt-rt-base = "6.12.27"
SRCREV_machine:kb-v6.12-standard-preempt-rt-bcm-2xxx-rpi ?= "53528b30a1a9c3578f32a7150a90febbada06b00"
LINUX_VERSION:kb-v6.12-standard-preempt-rt-bcm-2xxx-rpi = "6.12.27"
SRCREV_machine:kb-v6.12-standard-preempt-rt-nxp-sdk-6.12-nxp-soc ?= "0b7a37c6a17037f81e5120ce7b805e3733bb3d21"
LINUX_VERSION:kb-v6.12-standard-preempt-rt-nxp-sdk-6.12-nxp-soc = "6.12.27"
SRCREV_machine:kb-v6.12-standard-preempt-rt-x86 ?= "5eab9b167252984694bc9d4555c67d2e47ffa95c"
LINUX_VERSION:kb-v6.12-standard-preempt-rt-x86 = "6.12.27"
SRCREV_machine:kb-v6.12-standard-qemuppc ?= "5b22e7aef539a991b75fa45101cbc02051327cb6"
LINUX_VERSION:kb-v6.12-standard-qemuppc = "6.12.27"
SRCREV_machine:kb-v6.12-standard-tiny-arm-versatile-926ejs ?= "bec43e0bc0f2dc7728a2b586c1e95d5193e0f32d"
LINUX_VERSION:kb-v6.12-standard-tiny-arm-versatile-926ejs = "6.12.27"
SRCREV_machine:kb-v6.12-standard-tiny-base ?= "5b22e7aef539a991b75fa45101cbc02051327cb6"
LINUX_VERSION:kb-v6.12-standard-tiny-base = "6.12.27"
SRCREV_machine:kb-v6.12-standard-tiny-x86 ?= "5b22e7aef539a991b75fa45101cbc02051327cb6"
LINUX_VERSION:kb-v6.12-standard-tiny-x86 = "6.12.27"
SRCREV_machine:kb-v6.12-standard-x86 ?= "5b22e7aef539a991b75fa45101cbc02051327cb6"
LINUX_VERSION:kb-v6.12-standard-x86 = "6.12.27"
SRCREV_machine:kb-v6.12-standard-xilinx-zynqmp ?= "5b22e7aef539a991b75fa45101cbc02051327cb6"
LINUX_VERSION:kb-v6.12-standard-xilinx-zynqmp = "6.12.27"

# yocto-kernel-cache entries
KERNEL_CACHE_BRANCH_6.12 = "yocto-6.12"
SRCREV_meta_6.12 = "a50ff542f8d79235030741f9e850d34768907d2d"
