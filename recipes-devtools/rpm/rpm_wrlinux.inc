FILESEXTRAPATHS:append := ":${THISDIR}/rpm"

# Add the keyring directory where the keys are placed in the macros.krp
# file.
PACKAGECONFIG[keyringpath] = ",,,"
OVERRIDES .= "${@['', ':rpm-keyring-path']['keyringpath' in (d.getVar('PACKAGECONFIG', True) or "").split()]}"
SRC_URI:append:rpm-keyring-path = " \
    file://macros.krp \
    file://0001-do-not-limit-the-format-of-key-file.patch \
"

# Enforce signature checking and verification
PACKAGECONFIG[enforcesig] = ",,,"
OVERRIDES .= "${@['', ':rpm-enforce']['enforcesig' in d.getVar('PACKAGECONFIG', True).split()]}"
CFLAGS:append:rpm-enforce = " -DMANDATORY_KNOWN_SIG"
SRC_URI:append:rpm-enforce = " \
    file://0002-rpm-require-mandatory-signature.patch"

do_install:append:rpm-keyring-path () {
    install -d ${D}${sysconfdir}/rpm/
    install -d -m 700 ${D}${sysconfdir}/rpm/keys/
    install -m 0644 ${UNPACKDIR}/macros.krp ${D}${sysconfdir}/rpm/
}
