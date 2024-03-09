`volatile` tells compiler that the variable can change in ways that may be apparent to the compiler, and so it should not make assumptions about the behavior of variable.

`volatile` reduces performance and thus designs that necessitate use of `volatile` and use of `volatile` itself should be avoided.