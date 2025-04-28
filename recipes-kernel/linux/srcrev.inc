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
SRCREV_machine:kb-v6.12-base ?= "83b4161a63b87ce40d9f24f09b5b006f63d95b7c"
LINUX_VERSION:kb-v6.12-base = "6.12.23"
SRCREV_machine:kb-v6.12-standard-arm-versatile-926ejs ?= "dfeb3f6f2658b9d6ae4d5abebc184bd498dd59e9"
LINUX_VERSION:kb-v6.12-standard-arm-versatile-926ejs = "6.12.23"
SRCREV_machine:kb-v6.12-standard-base ?= "c2c450e032c7bf2653e50fc0a87329ce5660b6be"
LINUX_VERSION:kb-v6.12-standard-base = "6.12.23"
SRCREV_machine:kb-v6.12-standard-bcm-2xxx-rpi ?= "c2c450e032c7bf2653e50fc0a87329ce5660b6be"
LINUX_VERSION:kb-v6.12-standard-bcm-2xxx-rpi = "6.12.23"
SRCREV_machine:kb-v6.12-standard-beaglebone ?= "c2c450e032c7bf2653e50fc0a87329ce5660b6be"
LINUX_VERSION:kb-v6.12-standard-beaglebone = "6.12.23"
SRCREV_machine:kb-v6.12-standard-mti-malta32 ?= "8c15ba1838fe0cb24f1ced0b24dedad562dbfd7a"
LINUX_VERSION:kb-v6.12-standard-mti-malta32 = "6.12.23"
SRCREV_machine:kb-v6.12-standard-mti-malta64 ?= "8a34918e22d2fc3b37282d1929e760747762b74e"
LINUX_VERSION:kb-v6.12-standard-mti-malta64 = "6.12.23"
SRCREV_machine:kb-v6.12-standard-nxp-sdk-6.12-nxp-soc ?= "49ff61d863c2c7d41f7723995332e900ad09ac26"
LINUX_VERSION:kb-v6.12-standard-nxp-sdk-6.12-nxp-soc = "6.12.23"
SRCREV_machine:kb-v6.12-standard-preempt-rt-arm-versatile-926ejs ?= "8c77ad2a7b51d16657c9be7e4e1111bb78902555"
LINUX_VERSION:kb-v6.12-standard-preempt-rt-arm-versatile-926ejs = "6.12.23"
SRCREV_machine:kb-v6.12-standard-preempt-rt-base ?= "8569a61bf30561b620c3171431906cd8ddb7d095"
LINUX_VERSION:kb-v6.12-standard-preempt-rt-base = "6.12.23"
SRCREV_machine:kb-v6.12-standard-preempt-rt-bcm-2xxx-rpi ?= "7933eb9c8e4e460b7c49c59305bd4018e3ff5e6f"
LINUX_VERSION:kb-v6.12-standard-preempt-rt-bcm-2xxx-rpi = "6.12.23"
SRCREV_machine:kb-v6.12-standard-preempt-rt-nxp-sdk-6.12-nxp-soc ?= "cb5ceb59933c907fd1e47e279f11ba0c9e672470"
LINUX_VERSION:kb-v6.12-standard-preempt-rt-nxp-sdk-6.12-nxp-soc = "6.12.23"
SRCREV_machine:kb-v6.12-standard-preempt-rt-x86 ?= "0824fabb16a0337a24b1d52306a2494c5bbfb023"
LINUX_VERSION:kb-v6.12-standard-preempt-rt-x86 = "6.12.23"
SRCREV_machine:kb-v6.12-standard-qemuppc ?= "c2c450e032c7bf2653e50fc0a87329ce5660b6be"
LINUX_VERSION:kb-v6.12-standard-qemuppc = "6.12.23"
SRCREV_machine:kb-v6.12-standard-tiny-arm-versatile-926ejs ?= "90a69e83b90ab797ad31f9d31fa78705fe812849"
LINUX_VERSION:kb-v6.12-standard-tiny-arm-versatile-926ejs = "6.12.23"
SRCREV_machine:kb-v6.12-standard-tiny-base ?= "c2c450e032c7bf2653e50fc0a87329ce5660b6be"
LINUX_VERSION:kb-v6.12-standard-tiny-base = "6.12.23"
SRCREV_machine:kb-v6.12-standard-tiny-x86 ?= "c2c450e032c7bf2653e50fc0a87329ce5660b6be"
LINUX_VERSION:kb-v6.12-standard-tiny-x86 = "6.12.23"
SRCREV_machine:kb-v6.12-standard-x86 ?= "c2c450e032c7bf2653e50fc0a87329ce5660b6be"
LINUX_VERSION:kb-v6.12-standard-x86 = "6.12.23"
SRCREV_machine:kb-v6.12-standard-xilinx-zynqmp ?= "c2c450e032c7bf2653e50fc0a87329ce5660b6be"
LINUX_VERSION:kb-v6.12-standard-xilinx-zynqmp = "6.12.23"

# yocto-kernel-cache entries
KERNEL_CACHE_BRANCH_6.12 = "yocto-6.12"
SRCREV_meta_6.12 = "d36334a8b9597faf3978548085097c3b54d462d1"
