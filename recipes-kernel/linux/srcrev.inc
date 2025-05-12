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
SRCREV_machine:kb-v6.12-base ?= "f08cdc6cc92e3d23a05745f0f12f8caa348a27b4"
LINUX_VERSION:kb-v6.12-base = "6.12.28"
SRCREV_machine:kb-v6.12-standard-arm-versatile-926ejs ?= "f9767e83fd62a9807a62c2f6d2733fe2f5f792fd"
LINUX_VERSION:kb-v6.12-standard-arm-versatile-926ejs = "6.12.28"
SRCREV_machine:kb-v6.12-standard-base ?= "aaade4403631dc295fda2ed1f949c2820e409daf"
LINUX_VERSION:kb-v6.12-standard-base = "6.12.28"
SRCREV_machine:kb-v6.12-standard-bcm-2xxx-rpi ?= "aaade4403631dc295fda2ed1f949c2820e409daf"
LINUX_VERSION:kb-v6.12-standard-bcm-2xxx-rpi = "6.12.28"
SRCREV_machine:kb-v6.12-standard-beaglebone ?= "aaade4403631dc295fda2ed1f949c2820e409daf"
LINUX_VERSION:kb-v6.12-standard-beaglebone = "6.12.28"
SRCREV_machine:kb-v6.12-standard-mti-malta32 ?= "53f5fd2e711999de5fef3b4c336482a900a292d7"
LINUX_VERSION:kb-v6.12-standard-mti-malta32 = "6.12.28"
SRCREV_machine:kb-v6.12-standard-mti-malta64 ?= "b5d3ac10319c3de37ef49e685b1379f831d355b1"
LINUX_VERSION:kb-v6.12-standard-mti-malta64 = "6.12.28"
SRCREV_machine:kb-v6.12-standard-nxp-sdk-6.12-nxp-soc ?= "4b8f4966fa90307f2857d40228076b9f4b255801"
LINUX_VERSION:kb-v6.12-standard-nxp-sdk-6.12-nxp-soc = "6.12.28"
SRCREV_machine:kb-v6.12-standard-preempt-rt-arm-versatile-926ejs ?= "383f763d05afcb28f8459a05a3f4f00dfcaecbcd"
LINUX_VERSION:kb-v6.12-standard-preempt-rt-arm-versatile-926ejs = "6.12.28"
SRCREV_machine:kb-v6.12-standard-preempt-rt-base ?= "25c4a5115a23de065dd0a75ad7a95cd9efe4101c"
LINUX_VERSION:kb-v6.12-standard-preempt-rt-base = "6.12.28"
SRCREV_machine:kb-v6.12-standard-preempt-rt-bcm-2xxx-rpi ?= "d85ee08e6d151c5fa77a8714f803a6d25a2a00ce"
LINUX_VERSION:kb-v6.12-standard-preempt-rt-bcm-2xxx-rpi = "6.12.28"
SRCREV_machine:kb-v6.12-standard-preempt-rt-nxp-sdk-6.12-nxp-soc ?= "6dff8e7a9dd94975d7a778bf641a1cc454e20b95"
LINUX_VERSION:kb-v6.12-standard-preempt-rt-nxp-sdk-6.12-nxp-soc = "6.12.28"
SRCREV_machine:kb-v6.12-standard-preempt-rt-x86 ?= "9bb199eafb3967c3862d073ac53577058769ba84"
LINUX_VERSION:kb-v6.12-standard-preempt-rt-x86 = "6.12.28"
SRCREV_machine:kb-v6.12-standard-qemuppc ?= "aaade4403631dc295fda2ed1f949c2820e409daf"
LINUX_VERSION:kb-v6.12-standard-qemuppc = "6.12.28"
SRCREV_machine:kb-v6.12-standard-tiny-arm-versatile-926ejs ?= "84074947035074d438eba52a0cc9e6fccd4245dd"
LINUX_VERSION:kb-v6.12-standard-tiny-arm-versatile-926ejs = "6.12.28"
SRCREV_machine:kb-v6.12-standard-tiny-base ?= "aaade4403631dc295fda2ed1f949c2820e409daf"
LINUX_VERSION:kb-v6.12-standard-tiny-base = "6.12.28"
SRCREV_machine:kb-v6.12-standard-tiny-x86 ?= "aaade4403631dc295fda2ed1f949c2820e409daf"
LINUX_VERSION:kb-v6.12-standard-tiny-x86 = "6.12.28"
SRCREV_machine:kb-v6.12-standard-x86 ?= "aaade4403631dc295fda2ed1f949c2820e409daf"
LINUX_VERSION:kb-v6.12-standard-x86 = "6.12.28"
SRCREV_machine:kb-v6.12-standard-xilinx-zynqmp ?= "aaade4403631dc295fda2ed1f949c2820e409daf"
LINUX_VERSION:kb-v6.12-standard-xilinx-zynqmp = "6.12.28"

# yocto-kernel-cache entries
KERNEL_CACHE_BRANCH_6.12 = "yocto-6.12"
SRCREV_meta_6.12 = "dbf27c65983541ec12f26dc63efa0289ff16e1e3"
