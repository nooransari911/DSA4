The most fundamental search algorithm. ```O(V+E)``` time complexity.

can be used for:
1. count connected components
2. connectivity
3. bridges/articulation points


Visits one unvisited adjacent node of ```r```. If such a node does not exist, then backtracks. For every node ```r```.


##
RECURSIVE RACKET

```C
#lang racket


(require racket/trace)







(define ip1 (list 0 (list 1 1) (list 2 2)))
(define ip3 (list 5 4))
(define ip2 (list (list 0 (list 1 2) (list 1 2))
                  (list 1 (list 0 2 3 4) (list 1 2 3 4))
                  (list 2 (list 0 1) (list 1 1))
                  (list 3 (list 1 5) (list 1 5))
                  (list 4 (list 1) (list 1))
                  (list 5 (list 3 6 7 8) (list 3 6 7 8))
                  (list 6 (list 5) (list 5))
                  (list 7 (list 5 8) (list 5 8))
                  (list 8 (list 5 7 9) (list 5 7 9))
                  (list 9 (list 8) (list 8))))

(define (visitedf visited curr)
  [cond
    [(empty? visited)
     1]
    [(= curr (first visited))
     0]
    [else
     (visitedf (rest visited) curr)]
   ])

(define (key a curr)
  [cond
    [(empty? a)
     curr]
    [(= curr (first (first a)))
     (first a)]
    [else
     (key (rest a) curr)]
   ])

(define (summonidgroup idgroup currentid)
  [cond
    [(empty? idgroup)
     (list currentid)]
    [(= currentid (first (first idgroup)))
     (first idgroup)]
    [else
     (summonidgroup (rest idgroup) currentid)]
   ])

(define (catch1 current)
  [cond
    [(empty? (rest current))
     ]
    [else
     (first (first (rest current)))]])

(define (DFS i original current q visited post currentid idgroup)
  [cond
		[(empty? (first (rest current)))  //when no unvisited nodes from current node exist, append to post
     (DFS (- i 1) original (key original (first (rest q)))
          (rest q) visited (append (list (first current)) post)
          currentid idgroup)]
    [else
     (define next (first (first (rest current))))
     [cond
       [(empty? visited)  // initialize
        (DFS i original current
             (append (list (first current)) q) (append (list (first current)) visited) post
             currentid (append (list (first current)) idgroup))]
       [(= 0 i)  //terminated recursion
        (list visited (append (list (first (first original))) post) idgroup)]
       [(= 0 (visitedf visited next))  //next node is already visited
        (DFS i original (append (list (first current)) (append (list (rest (first (rest current)))) (rest (rest current))))
             q visited post
             currentid idgroup)]
       [else  //append to visited, pre
        (DFS (- i 1) original (key original next)
             (append (list next) q) (append (list next) visited) post
             currentid (append (list next) idgroup))]
       ]]])


(trace DFS)
;;(trace key)
(trace visitedf)
(trace summonidgroup)

;;(define original ip2)
;;(define modified original)
; 


(DFS 18 ip2 (first ip2) '() '() '() 1 '())
```

#### GENERAL ALGORITHM ::
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


(define (DFS counter original current_node q visited post currentid idgroup)
  [cond
	[when no unvisited nodes from current_node exist, 
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
       [if next node is already visited, then
		    [curent_node = drop the immediate neighbour node in current_node list;
		    ]
       [else append to visited
        [counter = counter--;
        current_node = key of the **first** immediate neighbour node;
        q, visited, idgroup = append **first** immediate neighbour node to q, visited, idgroup;
        ]
```


