## Ports, latches, TRIS
<type, configures pin as/relevant for>

- `TRIS`, input/output
- `LAT`, output
- `PORT`, input

- `ANSEL`, analog/digital
- `WPU`, internal pull-up register




- `TRIS` = 0/1 for output/input
- `LAT`  = 0/1 for output = low/high
- `PORT` = 0/1 for input = low/high

- `ANSEL`= 0/1 for digital/analog
- `WPU`  = 0/1 for disable/enable internal pull-up resistor


Use `TRISBbits.TRISB0`, `LATBbits.LATB0`, `PORTBbits.PORTB0` for using `RB0`.


Write to `LAT` for output pins; read `PORT` for input pin.
