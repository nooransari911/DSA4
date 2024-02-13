
# Chapter 1
## The Role of ALogrithms in Computing


*Statement* of a *problem* defines a relationship between input and output, possiblly with additional constraints on input and output.

*Instance of a problem* is any input that satisfies the constraints on input as defined in the problem.


An *algorithm* is a sequence of computational steps that transform *input* into *output*. Algorithm is a tool for solving a well-defined *computational problem*.


An algorithm *solves* a computational problem if it produces correct output for *every* valid input. An algorithm *halts* if it finishes its computing in finite time. An algorithm that is correct and halts is said to *solve* problem.


A *data structure* is a way to store and organize data in order to facilitate access and modifications. No data structure works best for *all* algorithms and using most appropriate data structure is critical for designing fast and efficient algorithms.


Machine learning can be thought of as a method for performing algorithmic tasks without explicitly designing an algorithm, but instead inferring patterns from data and thereby automatically learning a solution. At first glance, it may seem that machine learning may make learning about algorithms unnecessary.

However. the opposite is true. Machine learning is itself a collection of algorithms, just under a different name. Furthermore, it currently seems that the successes of machine learning are mainly for problems for which we, as humans, do not really understand what the right algorithm is. Prominent examples include computer vision and automatic language translation. For algorithmic problems that humans understand well, such as most of the problems in this book, efficient algorithms designed to solve a specific problem are typically more successful than machine-learning approaches.

Data science is an interdisciplinary field with the goal of extracting knowledge and insights from structured and unstructured data. Data science uses methods from statistics, computer science, and optimization. The design and analysis of algorithms is fundamental to the field. The core techniques of data science, which overlap significantly with those in machine learning, include many of the algorrithms in this book.




# Chapter 2
## Getting Started


## Algorithm 1
### Insertion Sort


Loop invariants are certain properties that remain true for all iterations of a a loop. Loop invariants help to prove the correctness of any algorithm.


Properties of loop invariant ::

- Initialization: It is true prior to the ûrst iteration of the loop.
- Maintenance: If it is true before an iteration of the loop, it remains true before the next iteration.
- Termination: The loop terminates, and when it terminates, the invariant--usually along with the reason that the loop terminated--gives us a useful property that helps show that the algorithm is correct.

WHen the first 2 properties hold, loop invariant is true before every iteration of the loop. The third property is perhaps the most important one, since you are using the loop invariant to show correctness.


Loop Invariant proof for algorithm 1
- Initialization ::
A [1:i-1] is A [1]. A [1:i-1] consists of A [1:i-1]. A [1:i-1] is sorted.
- Maintenence ::
The for loop moves every element in A [1:i-1] till it finds correct position for A [i]. Then it inserts A [i] at that position. Then the subarray A [1:i-1] consists only of elements originally in A [1:i-1], but the elemnts are now in sorted order. nOW INCREMENT i to preserve invariant.
- Termination ::
The loop terminates once i equals n+1. Substituting n+1 for i int loop invariant statement yields: the subarray A [1:n] consists of the elements originally in A [1:n], but in sorted order. Hence, the algorithm is correct.


*Analyzing* an algorithm has come to mean predicting the resources that the algo-
rithm requires.

Exact definition of *input size* depends upon the exact problem under consideration. It can mean number of items in the input, total number of bits, or a combination of multiple numbers. Exact definition of input size will be explicitly stated in the problem.


The *running time* of an algorithm on a particular input is the number of instructions and data accesses executed

The running time of the algorithm is the sum of running times for each statement executed. A statement that takes ck steps to execute and executes m times contributes (ck\*m) to the total running time. We usually denote the running time of an algorithm on an input of size n by T(n). T(n) is the sum of all such values of (ck\*m).


Doing this for Insertion sort, worst-case running time is of the form (an^2+bn+c), best-case running time is of the form (an+b). Worst-case running time is proportional to (n^2), best-case runnign time is proportional to (n).


Henceforth, we will focus only on worst-case running time.
- The worst-case running time of an algorithm gives an upper bound on the running time for *any* input. Upper bound gives a guarantee that the algorithm never takes any longer.
- For some algorithms, the worst case occurs fairly often. For example, in searching a database for a particular piece of information, the searching algorithm’s worst case often occurs when the information is not present in the database. In some applications, searches for absent information may be frequent.
- The "average case" is often roughly as bad as the worst case.


In some particular cases, we’ll be interested in the average-case running time of an algorithm. The scope of average-case analysis is limited, because it may not be apparent what constitutes an "average" input for a particular problem. Often, we’ll assume that all inputs of a given size are equally likely. In practice, this assumption may be violated, but we can sometimes use a randomized algorithm, which makes random choices, to allow a probabilistic analysis and yield an expected running time.


Henceforth, we are interested only in *order of growth*. First we ignored exact statement cost. Then we dropped abstract running costs with constants a, b, c.

Now we consider only the highest-order term and drop the remaining terms. We also drop the constants. Then worst-case running time for insertion sort becomes n^2.


Algorithm with order of growth n^3 will take more time than algorithm with order of growth n^2 for sufficiently large valeus of n.


To highlight order of growth, we use theta notation Θ (n). Insertion sort has a worst-case running time of order Θ (n^2).




*Designing* algorithms. Algorithms can be *incremental* or *divide-and-conquer*.

In incremental method, we progressively solve smaller parts of problem. In divide-and-conquer, we break the problem into a similar problem at smaller size, solve the subproblems recursively, and then combine these solutions to create a solution to the original problem.

In the divide-and-conquer method::
1. if the problem is small enough--called the base case--you just solve it directly without recursing
2. otherwise--called the recursive case--you perform three characteristic steps:
		Divide the problem into one or more subproblems that are smaller instances of the same problem.
		Conquer the subproblems by solving them recursively.
		Combine the subproblem solutions to form a solution to the original problem.


Incremental: Insertion sort
	For each element in A[i], insert it into its proper place in A[1:i] having already sorted A[1:i-1].

Divide-and-conquer: Merge sort
- **Divide**: Divide the subarray A[p:r] to be sorted into two adjacent subarrays, each of half the size.
		To do so, compute the midpoint q of A[p:r] by taking the average of p and r, and divide A[p:r] into subarrays A[p:q] and A[q+1:r]
- **Conquer**: Conquer by sorting each of the two subarrays A[p:q] and A[q+1:r] recursively using merge sort.
- **Combine**: Combine by merging the two sorted subarrays A[p:q] and A[q+1:r] back into A[p:r] producing the sorted answer.


Analyzing merge part:
The for loops cumulatively take (n\*C1) time as the entire array A[p:r] is copied into L or R arrays. The while loops cumulatively take (n\*C2) time as the three while loops cumulatively copy all n elements in L and R arrays into A array.

Thus, the for loops collectively have a worst-case running time of Θ (n). The three while loops collectively also have a worst-case running time of Θ (n).


Analyzing merge-sort part:
Merge-sort recursively calls itself till A has zero or one elements in it. Then it calls merge to merge the elements


Analyzing merge-sort algorithm ::
Let the worst-case running time of merge-sort algorithm be T (n).

Merge-sort is constant-time for small enough n, say n<=n0.

For other values of n, suppose the problem is divided into a parts each of size (n/b) with every division. Time to solve a problems each of size (n/b) is (a\*T (n/b)).

Suppose division takes D (n) time and combining takes C (n) time. Then T (n) becomes

T (n) = --|-- Θ (1), n<=n0,
		  |-- D (n) + C (n) + (a\*T (n/b)) otherwise.


- Divide:
	As divide step is just computing middle of array, it is constant-time, i.e., D (n) = Θ (1)

- Conquer:
	Problem is divided into 2 problems each of size (n/2). Thus a=2, b=2 and conquer time is (2\*T (n/2))

- Combine:
	Combine is merge part of algorithm. Merge is Θ (n) as previously shown.


Thus T (n) becomes ::

T (n) = --|-- Θ (1), n<=n0,
		  |-- θ(1) + θ (n) + (2\*T (n/2)) otherwise.

i.e.,
T (n) = --|-- Θ (1), n=1,
		  |-- θ (n) + (2\*T (n/2)) otherwise.
dropping Θ (1).


Thus T (n) = Θ (n\*log (n))
