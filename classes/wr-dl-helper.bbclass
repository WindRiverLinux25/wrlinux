#
# Copyright (C) 2024 Wind River Systems, Inc
#
# SPDX-License-Identifier: GPL-2.0-only
#

addhandler append_dl_to_premirrors
append_dl_to_premirrors[eventmask] = "bb.event.ConfigParsed"
python append_dl_to_premirrors() {
    import glob
    """
    The setup.py will create symlinks from wrlinux-src-dl/downloads to the dl
    layers, so the dl layers don't have to be in PREMIRRORS, but the sources may be
    added to dl layers for testing during development, this handler checks and
    adds them when needed.
    """
    wrlinux_src_dl = d.getVar('LAYER_PATH_wrlinux-src-dl')
    if not wrlinux_src_dl:
        return
    layers_topdir = os.path.dirname(wrlinux_src_dl)
    tarballs = glob.glob('%s/*-dl/downloads/*' % layers_topdir)
    shallow_tarballs = glob.glob('%s/*-gitshallow-dl/*' % wrlinux_src_dl)
    symlinks = [os.path.basename(s) for s in glob.glob('%s/downloads/*' % wrlinux_src_dl)]
    to_add = set()
    for t in tarballs + shallow_tarballs:
        if '/wrlinux_src_dl/' in t:
            continue
        if os.path.basename(t) in symlinks:
            continue
        to_add.add(os.path.dirname(t))
    for add in to_add:
        add = os.path.abspath(add)
        premirrors = ".*://.*/.* file://%s/ \n" % add
        bb.note('Appending "%s" to PREMIRRORS' % premirrors.strip())
        d.appendVar('PREMIRRORS', ' %s' % premirrors)
}
