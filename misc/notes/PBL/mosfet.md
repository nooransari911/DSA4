## MOSFET
- [When is a MOSFET more appropriate as a switch than a BJT?](https://electronics.stackexchange.com/questions/13079/when-is-a-mosfet-more-appropriate-as-a-switch-than-a-bjt)
- Need to fully charge gate capacitance to fully turn on MOSFET; need a gate driver capable of pushing very large currents for fast switching;
- Need to minimize time spent in ohmic region;
- Power dissipation is the primary limit, not the current rating.
- Vds rating should be 1.5x-2x the maximum Vs in circuit.
- Look for DC operating region in safe operating area graph.


## Current rating
- Current rating is at 25C. Current rating drops very rapidly at higher temperatures that are more realistic.


## Power dissipation
- Power dissipation is the primary limit, not the current rating.
- Current rating and all ratings in general are *ridiculously* optimistic.


## Ratings and MOSFETS
I = sqrt (0.2 / 2 * Rds)

- IRLB8721PBF:      Rs 87;   30V;   2.86A@    [0.2W, 100C];
- IRLB8748PBF:      Rs 90;   30V;   3.85A@    [0.2W, 100C];
- IRL7833PBF:       Rs 154;  30V;   4.588A@   [0.2W, 100C];
- IPP17N25S3:       Rs 190;  250V;  0.817A@   [0.2W, 100C];
- IQDH29NE:         Rs 360;  25V;   19A@      [0.2W, 100C];
- IGL[R,D]60R190D1: Rs 500;  600V;  0.6742A@  [0.2W, 100C];
- IGOT60R070D1:     Rs 1200; 600V;  1.042A@   [0.2W, 100C];


## Drivers
- IR2233J
- IR2233S
- 6EDL04N
