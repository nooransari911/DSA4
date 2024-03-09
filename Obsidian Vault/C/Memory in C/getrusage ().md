`getrusage ()` gets resource used by process.

Getting memory used by process ::

```C
# include <unistd, sys/resources>


long get_memory_usage (int baseline) {
	struct rusage current;
	
	getrusage (RUSAGE_SELF, &current);
	return (baseline - current.ru_maxrss);
}


int main () {
	long baseline = get_memory_usage (0);
	
	/*
	Your code here
	*/
	
	printf ("Memory used: %ld", get_memory_usage (baseline));
}
```