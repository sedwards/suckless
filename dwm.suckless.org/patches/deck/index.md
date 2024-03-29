deck layout
===========

Description
-----------
`deck` is a dwm-layout which is inspired by the TTWM window manager.
It applies the monocle-layout to the clients in the stack.
The master-client is still visible. The stacked clients are like
a deck of cards, hence the name.

deck-rmaster
------------
The vanilla patch doesn't respect the master-area which is defined by
the rmaster-patch. To make it work with the rmaster-patch apply the
dwm-deck-rmaster patch on top of the dwm-deck patch.

deck-tilegap
------------
The vanilla patch doesn't work properly with patches which add gaps.
This means that when the deck-layout is activated gaps are omitted.
To make it work with the tilegap-patch apply the dwm-deck-tilegap patch
on top of the dwm-deck patch.

Showcase
--------

	Tile :
	+-----------------+--------+
	|                 |        |
	|                 |  S1    |
	|                 |        |
	|        M        +--------+
	|                 |        |
	|                 |   S2   |
	|                 |        |
	+-----------------+--------+

	Deck :
	+-----------------+--------+
	|                 |        |
	|                 |        |
	|                 |        |
	|        M        |   S1   |
	|                 |        |
	|                 |        |
	|                 |        |
	+-----------------+--------+

Download
--------
* [dwm-deck-6.0.diff](dwm-deck-6.0.diff)
* [dwm-deck-rmaster-6.1.diff](dwm-deck-rmaster-6.1.diff)
* [dwm-deck-tilegap-6.1.diff](dwm-deck-tilegap-6.1.diff)

Author
------
* Jente Hidskes - `<jthidskes at outlook dot com>`
* Joshua Haase - `<hahj87 at gmail dot com>`
* Aleksandrs Stier
