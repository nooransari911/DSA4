`mmap()` can directly load file into memory.



```C
# include <unistd, sys/stat, sys/mman, stdio, stdlib>


int fd = open ("./file.txt", O_RDWR, S_IRUSR | S_IWUSR);
struct stat sb;

if (fstat (fd, &sb) == -1) {
	//gets size of file
	printf ("\ncannot get size of file");
}

char * file_in_memory = mmap (NULL, sb.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);

```



Note `fd` in `mmap ()` call. `mmap ()` directly loads data in file into memory and returns pointer to the memory.

This is for reading and writing to file. `MAP_SHARED` ensures that changes in memory will written back to the file in storage.

For reading only, use `O_RDONLY` in `open ()`, `PROT_READ` in `mmap ()`


`mmap ()` is ~2x faster than `fseek ()`, `fopen ()`.


`MAP_SHARED` means changes in memory are shared with rest of system. It can be used to communicate between processes.