singular borders
================

Description
-----------
`singular borders` changes the way DWM handles the borders. Firsty, borders
against the left, bottom and right screen edges are removed (they are placed
off-screen) and secondly, borders between clients now overlap eachother.


	Original behaviour :
	+-----------------+--------+
	|                 ||       |
	|                 ||  S1   |
	|                 ||       |
	|        M        |+=======|
	|                 ||       |
	|                 ||  S2   |
	|                 ||       |
	+-----------------+--------+


	New Behaviour :
	+-----------------+--------+
	                  |        
	                  |   S1  
	                  |        
	         M        +--------+
	                  |        
	                  |   S2   
	                  |        
	+                 +        +

Issues
------
* In a multi-monitor setup, you will see monitor one's borders on monitor two
  and vice-versa. This is because the borders on screen edges are simply placed
  off-screen.

Download
--------
* [dwm-6.0-singularborders.diff](dwm-6.0-singularborders.diff)
* [dwm-6.0-singularborders\_bstack.diff](dwm-6.0-singularborders_bstack.diff)

Author
------
* Jente Hidskes - `<jthidskes at outlook dot com>`
