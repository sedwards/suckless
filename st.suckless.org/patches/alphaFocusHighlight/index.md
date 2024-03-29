Alpha Focus Highlight Patch
===========================

![Screenshot](https://user-images.githubusercontent.com/9212314/68339985-e48a4880-00e5-11ea-8ff3-4e7086ad93c0.gif)

Description
-----------
This patch allows the user to specify two distinct opacity values; one for the focused- and one for
unfocused windows' background.
This enables the user to spot the focused window at a glance.

The *Alpha Highlight Focus Patch* patch is based on the
[Alpha Patch](https://st.suckless.org/patches/alpha/),
which is already applied in the patch file below. Most of the work has been performed by the
original authors of the Alpha Patch.

Notes Alpha Patch
-----------------
* Note that *you need an X composite manager* (e.g. compton, xcompmgr) to make this patch effective.
* The alpha value affects the default background only.
* The color designated by 'defaultbg' should not be used elsewhere.
* Embedding might fail after applying this patch.


Notes
-----
* In i3WM, the focus event is triggered twice for one specific window on a workspace (root);
  hence the alpha values are applied twice which appears as blinking.
* The patch is applied both to a non-patched version and to a patched version of st
  and can be tried out [here](https://github.com/juliusHuelsmann/st).


Download
--------
**Most Recent**:
* [st-alphaFocusHighlight-20191107-2b8333f.diff (Github)](https://github.com/juliusHuelsmann/st/releases/download/patchesV1/st-alphaFocusHighlight-20191107-2b8333f.diff)

**All Versions**:
* [st-alphaFocusHighlight-20191107-2b8333f.diff (Github)](https://github.com/juliusHuelsmann/st/releases/download/patchesV1/st-alphaFocusHighlight-20191107-2b8333f.diff)
* [st-alphaFocusHighlight-20191107-2b8333f.diff (attached)](st-alphaFocusHighlight-20191107-2b8333f.diff)

Authors of the Alpha Patch
--------------------------
* Eon S. Jeon - <esjeon@hyunmu.am>
* pr - <protodev@gmx.net> (0.5 port)
* Laslo Hunhold - <dev@frign.de> (0.6, git ports)
* Ivan J. - <parazyd@dyne.org> (git port)
* Matthew Parnell - <matt@parnmatt.co.uk> (0.7 port)
* Johannes Mayrhofer - <jm.spam@gmx.net> (0.8.1 port)
* Àlex Ramírez <aramirez@posteo.net> (0.8.1 pre-multiplication fix).


Authors of the Alpha-Focus Patch
--------------------------------
* Julius Hülsmann - <juliusHuelsmann [at] gmail [dot] com>
