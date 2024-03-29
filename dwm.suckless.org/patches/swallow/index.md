swallow
=======

Description
-----------
This patch adds "window swallowing" to dwm as known from Plan 9's windowing
system `rio`.

Clients marked with `isterminal` in config.h swallow a window opened by any
child process, e.g. running `xclock` in a terminal. Closing the `xclock` window
restores the terminal window in the current position.

This patch helps users spawning a lot of graphical programs from their command
line by avoiding cluttering the screen with many unusable terminals. Being deep
down in a directory hierarchy just does not make the use of dmenu feasible.

Dependencies
------------
* libxcb
* Xlib-libxcb
* xcb-res

These dependencies are needed due to the use of the latest revision of the X
Resource Extension which is unsupported in vanilla Xlib.

Download
--------
* [dwm-swallow-20170909-ceac8c9.diff](dwm-swallow-20170909-ceac8c9.diff)
* [dwm-swallow-6.1.diff](dwm-swallow-6.1.diff)
* [dwm-swallow-20160717-56a31dc.diff](dwm-swallow-20160717-56a31dc.diff)

Notes
-----
The window swallowing functionality requires `dwm` to walk the process tree,
which is an inherently OS-specific task. Only Linux is supported at this time.
Please contact one of the authors if you would like to help expand the list of
supported operating systems.

Only terminals created by local processes can swallow windows, and only windows
created by local processes can be swallowed.

Authors
-------
* Rob King - <jking@deadpixi.com>
* Laslo Hunhold - <dev@frign.de> (6.1, git port)
* Petr Šabata - <contyk@redhat.com> (bugfixes)
