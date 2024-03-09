#### TRADITIONAL BASIC GENERAL ALGORITHM ::
```C
original = (define ip2 (list (list 0 (list 1 2) (list 1 2))
                  (list 1 (list 0 2 3 4) (list 1 2 3 4))
                  (list 2 (list 0 1) (list 1 1))
                  (list 3 (list 1 5) (list 1 5))
                  (list 4 (list 1) (list 1))
                  (list 5 (list 3 6 7 8) (list 3 6 7 8))
                  (list 6 (list 5) (list 5))
                  (list 7 (list 5 8) (list 5 8))
                  (list 8 (list 5 7 9) (list 5 7 9))
                  (list 9 (list 8) (list 8))))


(define (BFS counter original current_node q visited post currentid idgroup)
  [cond
	//[when no unvisited nodes from current_node exist, 
			[counter = counter--;
			current_node = key of second latest node added to q, i.e, the node visited 
			immediately before;
			current_node = current_node;
			q = remove current_node from q;
			post = append current node top to post;
			]



    [else
     (define next (first (first (rest current))))
     [cond
		[if visited is empty 
			[append first node to q, visited, idgroup;
			]
			
		[if i = 0, then terminate recursion
			[append visited to (append (first (first original)) to post) to 
			idgroup;
			]
       //[if next node is already visited, then
		    [curent_node = drop the immediate neighbour node in current_node 
		    list;
		    ]
       [else append to visited
        [counter = counter--;
		    current_node = key of the **all unvisited** immediate neighbour node, i.e., 
			    1. filter out visited nodes from all neighbouring nodes,
			    2. merge neighbouring nodes of all unvisited nodes;
        q, visited, idgroup = append **all unvisited** immediate neighbour node to q, 
        visited, idgroup;
        ]
```


#### WITH DEPTH LEVEL::

```C
original = (define ip2 (list (list 0 (list 1 2) (list 1 2))
                  (list 1 (list 0 2 3 4) (list 1 2 3 4))
                  (list 2 (list 0 1) (list 1 1))
                  (list 3 (list 1 5) (list 1 5))
                  (list 4 (list 1) (list 1))
                  (list 5 (list 3 6 7 8) (list 3 6 7 8))
                  (list 6 (list 5) (list 5))
                  (list 7 (list 5 8) (list 5 8))
                  (list 8 (list 5 7 9) (list 5 7 9))
                  (list 9 (list 8) (list 8))))


(define (BFS_depth_level counter original current_node q visited post currentid idgroup)
  [cond
	//[when no unvisited nodes from current_node exist, 
			[counter = counter--;
			current_node = key of second latest node added to q, i.e, the node visited 
			immediately before;
			current_node = current_node;
			q = remove current_node from q;
			post = append current node top to post;
			]



    [else
     (define next (first (first (rest current))))
     [cond
		[if visited is empty 
			[append first node to q, visited, idgroup;
			]
			
		[if i = 0, then terminate recursion
			[append visited to (append (first (first original)) to post) to 
			idgroup;
			]
       //[if next node is already visited, then
		    [curent_node = drop the immediate neighbour node in current_node 
		    list;
		    ]
       [else append to visited
        [counter = counter--;
        depth_group = append current_node to current depth_level group;
        depth = depth + 1;
		current_node = key of the **all unvisited** immediate neighbour node, i.e., 
			    1. filter out visited nodes from all neighbouring nodes,
			    2. merge neighbouring nodes of all unvisited nodes;
			    3. merge keys of all unvisited neighbour nodes
        q, visited, idgroup = append **all unvisited** immediate neighbour node to q, 
        visited, idgroup;
        ]
```


#### CENTER OF TREE::
```c
Do BFS
Reach the leaf (dead) nodes
Remove the leaf nodes

Do BFS again
Repeat

If removing leaf nodes results in empty graph, then return current graph. This will be the final answer.
```