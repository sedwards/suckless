fullgaps
========

Description
-----------
This patch adds gaps between client windows. It is similar to [gaps](../gaps/),
but contains additional functionality:
* it also adds outer gaps (between the clients and the screen frame), as well
  as a gap between the master and stack area,
* it adds keybindings to change the gap size at runtime: [Alt]+[-]/[Alt]+[=] to
  decrease/increase the gap size and [Alt]+[Shift]+[=] to set it to zero.

The configuration variable `gappx` contains the default gap size.

Download
--------
* [dwm-fullgaps-6.2.diff](dwm-fullgaps-6.2.diff)

Author
------
* Maciej Sumalvico <macjan@o2.pl>
