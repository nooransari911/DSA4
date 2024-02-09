# 1
## Insertion Sort


Numbers to be sorted are known as *keys*. Typically, keys are associated with other data known as *sattelite data*. Keys and sattelite data form a *record*.


## Algorithm
```
insertion_sort (A, n)
	for i = 2 to n
	
	key = A [i]
	
	// Insert A [i] into A [i-1];
	// A [i-1] is sorted array;

	j = i-1
	while j>0 and A [j]>key
		A [j+1] = A [j]
		j = j-1

	A [j+1] = key
```



Loop Invariant ::
- At the start of each iteration of the for loop, the subarray A [1:i-1] consists of the elements originally in A [i:i-1] but in sorted order.
