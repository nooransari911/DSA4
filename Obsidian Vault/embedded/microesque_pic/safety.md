## Reentrant
Reentrant is when itr calls `func1 ()` while `func1 ()` is executing. Without reentrant software stack (disabled by default), it can lead to data corruption.

Set `Hybrid` in software stack in compiler options in MPLAB IDE.


## Atomicity
Itrs can lead to data corruption or read wrong value if itr access data when it is being used by some function.

Disable interrupts before operation to prevent this from happening.

`di () //disables itr
func1 ();//some function here
ei (); //enables itr
`
