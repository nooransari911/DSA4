## Interrupts
Interrupts execute certain code when a particular event/condition happens.

Interrupts are functions that are executed when a particular event/condition happens. Main function is paused and saved and interrupt functuon is executed. After the function is completed, main function resumes.


## Interrupts in PIC
Interrupt can be high priority or low priority. High priority interrupt can interrupt low priority interrupt.

There are 6 bits for every possible interrupt. 3 of these are common to all interrupts; remaining 3 are specific to every interrupt.

`pr: priority, itr: interrupt`


Global bits:
- `IPEN` enables/disables interrupt priotity
- `GIEL/PEIE` enables/disables low priority itrs
- `GIEH/GIE` enables high pr itrs and disables all itrs


Each itr source has name of peripheral followed by 3 bits: `IF` (itr flag), `IE` (itr enable), `IP` (itr pr).

Ex.: peripheral `TMR0` has 3 bits: `TMR0IF`, `TMR0IE`, `TMR0IP`.


`IF` is the actual itr signal. It goes high when a specific condition becomes true.
`IE` enables/disables itrs from the particular source.
`IP` is pr for the itr source.

`IE` = 0/1 to disable/enable itr; `IP` = 0/1 for low/high pr.


`PIR1` register has `IF` flags; `PIE1` has `IE` flags; `IPR1` has `IP` flags.
