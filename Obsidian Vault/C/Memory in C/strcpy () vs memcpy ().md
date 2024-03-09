`strcpy ()` expects strings, `memecpy ()` simply copies data.

`strcpy ()` copies data till `0` is encountered. So if source string is not null-terminated, then it will out-of-bounds looking for `0` and `SIGSEGV`.

`strcpy ()` also has number of bytes. It will copy `n` bytes.