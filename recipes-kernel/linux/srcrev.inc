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
SRCREV_machine:kb-v6.12-standard-arm-versatile-926ejs ?= "37a1fd13ca538e7785daf01434495a614bc55ead"
LINUX_VERSION:kb-v6.12-standard-arm-versatile-926ejs = "6.12.31"
SRCREV_machine:kb-v6.12-standard-base ?= "298aefdf4112e7c0a84522e4acf2c722e433c8a0"
LINUX_VERSION:kb-v6.12-standard-base = "6.12.31"
SRCREV_machine:kb-v6.12-standard-bcm-2xxx-rpi ?= "298aefdf4112e7c0a84522e4acf2c722e433c8a0"
LINUX_VERSION:kb-v6.12-standard-bcm-2xxx-rpi = "6.12.31"
SRCREV_machine:kb-v6.12-standard-beaglebone ?= "298aefdf4112e7c0a84522e4acf2c722e433c8a0"
LINUX_VERSION:kb-v6.12-standard-beaglebone = "6.12.31"
SRCREV_machine:kb-v6.12-standard-mti-malta32 ?= "2bcf58ea5aa19d54c436e63c59ab09b307e9ee8e"
LINUX_VERSION:kb-v6.12-standard-mti-malta32 = "6.12.31"
SRCREV_machine:kb-v6.12-standard-mti-malta64 ?= "6470f58a8f04951f202cf85afb4421d2e7ec9995"
LINUX_VERSION:kb-v6.12-standard-mti-malta64 = "6.12.31"
SRCREV_machine:kb-v6.12-standard-nvidia-sdk-5.15-nvidia-soc ?= "e84739376edc5f9137127a6f788ac5c3e7234d43"
LINUX_VERSION:kb-v6.12-standard-nvidia-sdk-5.15-nvidia-soc = "6.12.31"
SRCREV_machine:kb-v6.12-standard-nxp-sdk-6.12-nxp-soc ?= "04138e70a2d829a04fc98151cd06d1256acfc8e3"
LINUX_VERSION:kb-v6.12-standard-nxp-sdk-6.12-nxp-soc = "6.12.31"
SRCREV_machine:kb-v6.12-standard-preempt-rt-arm-versatile-926ejs ?= "b0115f7518bc37b7f9c486be973f851b1245f6f1"
LINUX_VERSION:kb-v6.12-standard-preempt-rt-arm-versatile-926ejs = "6.12.31"
SRCREV_machine:kb-v6.12-standard-preempt-rt-base ?= "7cb6d42c40de351ecab0a083aef260f84407de0d"
LINUX_VERSION:kb-v6.12-standard-preempt-rt-base = "6.12.31"
SRCREV_machine:kb-v6.12-standard-preempt-rt-bcm-2xxx-rpi ?= "ba1d76a8354ea63b3f661aabcd96f263d8d0056e"
LINUX_VERSION:kb-v6.12-standard-preempt-rt-bcm-2xxx-rpi = "6.12.31"
SRCREV_machine:kb-v6.12-standard-preempt-rt-nvidia-sdk-5.15-nvidia-soc ?= "ba6e70bba6be65b5beecd817dc642786fb0efc5c"
LINUX_VERSION:kb-v6.12-standard-preempt-rt-nvidia-sdk-5.15-nvidia-soc = "6.12.31"
SRCREV_machine:kb-v6.12-standard-preempt-rt-nxp-sdk-6.12-nxp-soc ?= "0de07364cadbb79b90a9636358816a34d3abffab"
LINUX_VERSION:kb-v6.12-standard-preempt-rt-nxp-sdk-6.12-nxp-soc = "6.12.31"
SRCREV_machine:kb-v6.12-standard-preempt-rt-x86 ?= "109c438b8a9963901c80bc5345e17c940872c19f"
LINUX_VERSION:kb-v6.12-standard-preempt-rt-x86 = "6.12.31"
SRCREV_machine:kb-v6.12-standard-qemuppc ?= "298aefdf4112e7c0a84522e4acf2c722e433c8a0"
LINUX_VERSION:kb-v6.12-standard-qemuppc = "6.12.31"
SRCREV_machine:kb-v6.12-standard-tiny-arm-versatile-926ejs ?= "fa8ececf5612fbb30866113862122994c81f3496"
LINUX_VERSION:kb-v6.12-standard-tiny-arm-versatile-926ejs = "6.12.31"
SRCREV_machine:kb-v6.12-standard-tiny-base ?= "298aefdf4112e7c0a84522e4acf2c722e433c8a0"
LINUX_VERSION:kb-v6.12-standard-tiny-base = "6.12.31"
SRCREV_machine:kb-v6.12-standard-tiny-x86 ?= "298aefdf4112e7c0a84522e4acf2c722e433c8a0"
LINUX_VERSION:kb-v6.12-standard-tiny-x86 = "6.12.31"
SRCREV_machine:kb-v6.12-standard-x86 ?= "298aefdf4112e7c0a84522e4acf2c722e433c8a0"
LINUX_VERSION:kb-v6.12-standard-x86 = "6.12.31"
SRCREV_machine:kb-v6.12-standard-xilinx-zynqmp ?= "298aefdf4112e7c0a84522e4acf2c722e433c8a0"
LINUX_VERSION:kb-v6.12-standard-xilinx-zynqmp = "6.12.31"

# yocto-kernel-cache entries
KERNEL_CACHE_BRANCH_6.12 = "yocto-6.12"
SRCREV_meta_6.12 = "ccf0820f3051935f9e39d9ad29aa3712aa48e090"
