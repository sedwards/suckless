ru\_gaps
========

Description
-----------
Runtime useless gaps

This patch adds gaps like [tilegap](../tilegap/) that are resizeable at runtime like [fullgaps](../fullgaps/),
but like [uselessgap](../uselessgap/) it removes gaps and borders when in monocle mode. 

This patch also incorporates the [noborder](../noborder/) patch, but without the check
for 'is not fullscreen', to make it work properly with [fakefullscreen](../fakefullscreen).

Notes
-----
You might want to set resizehints in config.h to zero to get smooth animations when increasing or decreasing gaps.

Download
--------
* [dwm-ru\_gaps-6.2.diff](dwm-ru_gaps-6.2.diff) - 24-07-2019

Apply the following patches on top of the previous patch to add 
additional layouts with resizeable gap support.

A copy of the [fibonacci](../fibonacci/), but with resizeable gaps. 
	(Window sizes do not scale correctly. Feel free to fix it.)
* [dwm-ru\_fibonacci-6.2.diff](dwm-ru_fibonacci-6.2.diff)

A copy of the [gaplessgrid](../gaplessgrid/), but with resizeable gaps.
* [dwm-ru\_gaplessgrid-6.2.diff](dwm-ru_gaplessgrid-6.2.diff) - 25-06-2019

A copy of the [bottomstack](../bottomstack/), but with resizeable gaps.
	(bstack layout works correctly. 
	 bstackhorizontal layout windows do not scale 100% correctly. Feel free to fix it ;) )
* [dwm-ru\_bottomstack-6.2.diff](dwm-ru_bottomstack-6.2.diff) - 24-07-2019

A copy of the [centeredmaster](../centeredmaster/), but with resizeable gaps.
* [dwm-ru\_centeredmaster-6.2.diff](dwm-ru_centeredmaster-6.2.diff) - 24-07-2019

A copy of the [deck](../deck/), but with resizeable gaps.
* [dwm-ru\_deck-6.2.diff](dwm-ru_deck-6.2.diff) - 24-07-2019

Authors
------
* Aaron Duxler <aaron.duxler@gmail.com>
* Rob Livesey <rlives6789@gmail.com>
