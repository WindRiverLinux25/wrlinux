IMAGE_INSTALL += " dpdk dpdk-tools dpdk-module"

BSP_NXP_DERIVED ??= ""
# NXP BSPs doesn't need dpdk-tools and dpdk-module package, so remove them for these BSPs.
IMAGE_INSTALL:remove = "${@bb.utils.contains_any('MACHINE', '${BSP_NXP_DERIVED}', 'dpdk-module dpdk-tools', '', d)}"

# Marvell BSPs doesn't need dpdk-module, so remove it for marvell BSPs.
IMAGE_INSTALL:remove:marvell-cn10xxx = "dpdk-module"
