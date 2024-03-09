- `memcpy (dest_pointer, src_pointer, n)` copies `n` bytes form `src_pointer` to `dest_pointer`. `memcpy ()` can copy to and from pointers of any data type.
- `memset (dest_pointer, value, n)` sets `n` bytes from `dest_pointer` to value.


```C
struct node * p1, * p2*;
char buffer [4096];

memset (buffer, 0, 4096);
memcpy (buffer, p1, sizeof (struct node));
p2 = (struct node *) (buffer);
```

Character array behaves as a pointer. So `a` in `char a [10]` will behave as a `char *` pointer.

You can use casting to serialize/deserialize structs.