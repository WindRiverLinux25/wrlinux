#
# Copyright (C) 2015 Wind River Systems, Inc.
#

OVERRIDES .= "${@bb.utils.contains('LICENSE_FLAGS_ACCEPTED', 'commercial_windriver', ':wr-themes', '', d)}"

DEFAULT_WALLPAPER ?= "gray"

LICENSE_FLAGS:wr-themes = "commercial_windriver"

DEPENDS += "libyaml"

EXTRA_OECONF:append = " --enable-desktop-icons --enable-file-icons --with-default-backdrop-filename=${datadir}/backgrounds/Windriver/windriver-${DEFAULT_WALLPAPER}-1.jpg"

RDEPENDS:${PN}:append:wr-themes = " wr-themes-wallpapers"
