# For the recipes which can't be handled by gen-vendor-revision.bbclass
# automatically, the format can be either of:
# VENDOR_REVISION:pn-<recipe> = ".<vr version>", for example:
#
# VENDOR_REVISION:pn-bash = ".vr2401"
#
# Or:
#
# VENDOR_REVISION[<last_4_dirs_to_recipe_version>.bb] ?= '.vr2401 ', for example:
#
# VENDOR_REVISION[meta_recipes-extended_bash_bash_5.2.21.bb] ?= '.vr2401 '
