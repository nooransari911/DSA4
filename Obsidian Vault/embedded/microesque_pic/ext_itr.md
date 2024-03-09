## External interrupts
External interrupts (ext itrs) are itrs caused by external means. These are named as `INT` followed by a number.


<Ext itr, register that ext itr is connected to>
`INT0`: `RB0`
`INT1`: `RB1`
`INT2`: `RB2`

`INT0` is always high pr, while `INT1`, `INT2` can be configured to be high/low pr.


Declaration of function for handling itrs (high if pr is disabled):
``` void __interrupt () ISR () {
  //code goes here
}```


Declaration of func for handling high pr itrs:
``` void __interrupt (high_priority) ISR_high () {
  //code goes here
}```


Declaration of func for handling low pr itrs:
``` void __interrupt (low_priority) ISR_low () {
  //code goes here
}```


Remember to clear `IF` flag for the corresponding itr when exiting ISR.




## Configuring itrs
Enable pin `RB1` as input. `TRISBbits.TRISB1=1`. Enable pin as digital. `ANSELBbits.ANSB1=0`


Configure global itr bits:
Enable itrs with `IPEN` bit in `RCON` register. Enable `GIEL`, `GIEH` bits in `INTCON` register.

Set `EDG1` bit in `INTCON2` register. 1 for rising edge trigerred, 0 for falling edge trigerred.


Configure local itr bits:
Next configure `IF`, `IE`, `IP` bits for the specific ITR. These bits are in `INTCON` or `INTCON3` registers.

Set `IF` bit as 0 to clear `IF` flag. Set `IE` as 1 to enable itr. Set `IP` as 0 for low pr, 1 for high pr.
