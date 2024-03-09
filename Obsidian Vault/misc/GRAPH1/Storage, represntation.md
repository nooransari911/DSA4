1. Adjacency matrix
A matrix. For matrix A with ```[row][column]``` represented as ```[i][j]```, ```A[i][j]``` represents the weight of edge going from node ```i``` to node ```j```.

Pros:
	Space efficient for dense graphs
	Edge lookup is constant time, ```O(1)```
	Simplest (or is it?), most primitive

Cons:
	Requires ```O(V^2)``` space
	Iterating over all edges takes ```O(V^2)``` time




2. Adjacency list
A list. Adjacent nodes and weight of edges to nodes are stored as list.

A --> \[(B,1), (C,32), (D,4), (F,45)]
Similarly for all other nodes

Pros:
	Space efficient for sparse graphs
	Iterating over all edges is efficient

Cons:
	Less space efficient for dense graphs
	Edge weight lookup is ```O(E)``` time





3. Edge list
A list. Triplets.

\[(A,B,1), (A,C,32), (A,D,4), (A,F,45)]
Similarly for all other nodes

Pros:
	Space efficient for sparse graphs
	Iterating over all edges is efficient

Cons:
	Less space efficient for dense graphs
	Edge weight lookup is ```O(E)``` time
