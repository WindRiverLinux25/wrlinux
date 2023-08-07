RECIPE_LIST_LAYERS:remove = "meta-anaconda"

# Recipes allowed for meta-openembedded/meta-gnome
WRL_RECIPES:gnome-layer += "\
    keybinder \
    libnma \
    libtimezonemap \
    metacity \
    network-manager-applet \
    usermode \
"

# Recipes allowed for meta-openembedded/meta-python
WRL_RECIPES:meta-python += "\
    python3-blivet \
    python3-blivetgui \
    python3-langtable \
    python3-meh \
    python3-ntplib \
    python3-ordered-set \
    python3-pid \
    python3-prctl \
    python3-pydbus \
    python3-pykickstart \
    python3-pyparted \
    python3-pyudev \
    python3-requests-file \
    python3-requests-ftp \
"

# Recipes allowed for meta-openembedded/meta-filesystems
WRL_RECIPES:filesystems-layer += "\
    ntfs-3g-ntfsprogs \
"

# Recipes allowed for meta-openembedded/meta-oe
WRL_RECIPES:openembedded-layer += "\
    libpwquality \
    libreport \
    libtar \
    fltk \
    glade \
    gnome-doc-utils-stub \
    isomd5sum \
    satyr \
    tigervnc \
    uthash \
    xmlrpc-c \
    libsass \
    sassc \
"
