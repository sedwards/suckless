swap focus
==========

Description
-----------
This patch makes it possible to switch focus with one single shortcut (alt-s)
instead of having to think if you should use alt-j or alt-k for reaching the
last used window.

Changes in 6.2
----------------
* Remember the previous tag and previous clients on each tag.
* If there is no previous client on the current tag (because it was moved or killed), 
  the next client on the current tag is focused.

Download
--------
* [dwm-swapfocus-6.2.diff](dwm-swapfocus-6.2.diff) (21.07.2019)
* [dwm-swapfocus-20160731-56a31dc.diff](dwm-swapfocus-20160731-56a31dc.diff)
* [dwm-swapfocus-6.0.diff](dwm-swapfocus-6.0.diff) (1482b) (20120406)
* [dwm-5.8.2-swap.diff](dwm-5.8.2-swap.diff) (dwm 5.8.2)

Author
------
* Lasse Engblom
* Jan Christoph Ebersbach - <jceb@e-jc.de>
* Aaron Duxler - <aaron.duxler@gmail.com> (6.2 port)
