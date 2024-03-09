`mmap (void * pointer, int length, int prot, int flags, int fd, int offset)` allocates memory.


```C
mamp (NULL, PAGESIZE, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANNOYMOUS, -1, 0)
```



Pointer is hint. `mmap ()` tries to allocate memory at the pointer. `NULL` is for no hint.

`PAGESIZE` is multiple of page size of OS.

`PROT` is for protection. It specifies access type. `PROT_READ` is for read-only, `PROT_WRITE` is for write-only.

`FLAGS` specify whether or not memory should be shared among processes.

Last two are for memory-mapped IO.