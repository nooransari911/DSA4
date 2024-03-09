## Bitwise operation in binary

AND `&`:

A | B | `AND`
X | 1 | X
X | 0 | `0`

From the truth table, it is clear that `AND` is 0 when B is 0. Thus, `AND` can be used for `clearing` bits.
AND the bit to be cleared with 0, AND all other bits with 1.


OR `|`:

A | B | `OR`
X | 0 | X
X | 1 | `1`

From the truth table, it is clear that `OR` is 1 when B is 1. Thus, `OR` can be used for `setting` bits.
OR the bit to be set with 1, OR all other bits with 0.


EXOR `^`:

A | B | `EXOR`
X | 0 | X
X | 1 | X'

From the truth table, it is clear that `EXOR` is 1 when both bits are different. Thus, `EXOR` can be used for `flipping` bits.
EXOR the bit to be flipped with 1, EXOR all other bits with 0.


## Complements : 1's, 2's
1s complement is inverting all bits. 2s complement is 1 added to 1s complement.




## Shift operations
`<<`, `>>` are for shifting left, right.

Shifting is equivalent to multiplication/division by base of system (in this case, 2).
