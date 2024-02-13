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




# 2
## Merge-Sort

## Algorithm: Merge (A, p, q, r)
```
nl = q-p+1  // length of A[p:q]
nr = r-q  // length of A[q+1:r]

let L[0:nl-1] and R[0:nr-1] be new arrays

for i = 0 to nl-1  //copy A[p:q] to L[0:nl-1]
	L[i]=A[p+i]
for j = 0 to nr-1  //copy A[q:r] to R[0:nr-1]
	R[i]=A[q+j+i]


i=0  // i indexes the smallest remaining element in L
j=0  // j indexes the smallest remaining element in R
k=p  // k indexes the location in A to fill

// As long as each of the arrays L and R contains an unmerged element, copy the smallest unmerged element back into A[p:r]


while i<nl and j<nr
	if L[i]<=R[j]
		A[k]=L[i]
		i=i+1
	else
		A[k]=R[j]
		j=j+1
	k=k+1


// Having gone through one of L and R entirely, copy the remainder of the other to the end of A[p:r]


while i<nl
	A[k]=L[i]
	i=i+1
	k=k+1
while j<nr
	A[k]=R[j]
	j=j+1
	k=k+1
```


## Algorithm: Merge-sort (A, p, r)
```
if p>=r
	return

//The floor function below means the greatest integer not greater than the value of division
q=floor ((p+r)/2)

Merge-sort (A,p,q)
Merge-sort (A,q+1,r)

//Merge A[p:q] and A[q+1:r] into A[p:r]
Merge (A,p,q,r)
```
