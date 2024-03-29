center
======

Description
-----------
This patch centers dmenu in the middle of the screen.

Previously this has been achieved through the [xyw
patch](//tools.suckless.org/dmenu/patches/xyw) and a bash script to calculate
the centered x and y positions. However, this is a slow and overly complex way
which is hard to integrate into programs which call dmenu directly, eg surf or
tabbed. On the other hand, This small standalone patch is instantaneous and
works globally.

With `dmenu-center-20191105-f1ca0d0.diff`, you can use _-c_ to center dmenu.

Download
--------
* [dmenu-center-20191105-f1ca0d0.diff](dmenu-center-20191105-f1ca0d0.diff)
* [dmenu-center-4.8.diff](dmenu-center-4.8.diff)

Authors
-------
* Ed van Bruggen <edvb@uw.edu>
* Nihal Jere <nihal@nihal.jere.xyz> (20191105)
