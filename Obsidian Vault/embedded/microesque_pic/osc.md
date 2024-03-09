## Oscillators
PICs can use internal or external oscillators. External oscs have higher accuracy and frequency than internal ones.

Supported operation modes :
- Int osc at compile time
- Int/ext osc at compile time
- Int/ext osc at 4x frequency at runt time
- Sec int osc at run time


<bit, register>:
- [Internal osc block] :: IRCF (OSCCON), MFIOSEL (OSCCON2), INTSRC (OSCTUNE)
- [Primary osc block] :: FOSC (CONFIG1H) (<config bit>), PLLEN (OSCTUNE)

IRCF selects int osc (selected int osc also depends upon value of MFIOSEL and INTSRC);
IRCF selects between HFINTOSC if MFIOSEL is 0, else selects between MF/LFINTOSC if MFIOSEL is 1;
MFIOSEL selects between HFINTOSC and MF/LFINTOSC;
INTSRC selects 31 kHz int osc;

FOSC config bit selects between int osc and ext osc;
PLLEN 1 to use internal 4x frequency PLL;


Clock freq can be output at (1/4 th) freq.

External osc are used for better accuracy.


__delay_ms/_us (x) create delay for x ms/us using XTAL_FREQ. Though timer-interrupt consume less power and do something else.
