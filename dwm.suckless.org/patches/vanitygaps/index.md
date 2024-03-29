vanitygaps
==========

Description
-----------
Inspired by some of the functionality of [i3-gaps](https://github.com/Airblader/i3) this patch adds (inner) gaps between client windows and (outer) gaps between windows and the screen edge in a flexible manner.

Named vanitygaps as it does not provide any real functionality as such and is purely a visual eyecandy that is perhaps best suited for people looking for that certain look and feel. That said this might look great on a monitor (for monitoring purposes).

The patch provides:

   * option to control all gaps in unison (like [fullgaps](../fullgaps))
   * option to control inner gaps in unison (like [gaps](../gaps/))
   * option to control inner and outer gaps separately
   * option to control the inner horizontal and vertical gaps separately
   * option to control the outer horizontal and vertical gaps separately
   * option to toggle gaps on and off
   * option to reset gaps back to default
   * option to show no outer gaps when there is only one window (smart gaps)
   * example keyboard shortcuts to change the gaps on the fly

The example keyboard shortcuts included are:

   * `Alt+Super+0` ― *toggle gaps on and off*
   * `Alt+Super+Shift+0` ― *reset gaps back to default*
   * `Alt+Super+h` ― *increase all gaps*
   * `Alt+Super+l` ― *decrease all gaps*
   * `Alt+Super+Shift+h` ― *increase outer gaps*
   * `Alt+Super+Shift+l` ― *decrease outer gaps*
   * `Alt+Super+Ctrl+h` ― *increase inner gaps*
   * `Alt+Super+Ctrl+l` ― *decrease inner gaps*
   * `Alt+y` ― *increase inner horizontal gaps*
   * `Alt+o` ― *decrease inner horizontal gaps*
   * `Alt+Ctrl+y` ― *increase inner vertical gaps*
   * `Alt+Ctrl+o` ― *decrease outer vertical gaps*
   * `Alt+Super+y` ― *increase outer horizontal gaps*
   * `Alt+Super+o` ― *decrease outer horizontal gaps*
   * `Alt+Shift+y` ― *increase outer vertical gaps*
   * `Alt+Shift+o` ― *decrease outer vertical gaps*

Nobody should need all of these, but they are included for demo purposes and for experimentation. Consider trimming these down to what you actually use.

NB: You may also want to disable `resizehints` to get even gaps.

Download
--------
* [dwm-vanitygaps-20190508-6.2.diff](dwm-vanitygaps-20190508-6.2.diff)

Author
------
* Stein Bakkeby <bakkeby@gmail.com>
