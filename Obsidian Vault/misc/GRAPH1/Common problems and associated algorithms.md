1. Shortest path: Find the shortest path from node A to node B. BFS (unweighted graph), Djisktra, Bellman-Ford, Floyd-Warshall, A*
2. Connectivity: Does a path from node A to node B exist? DFS
3. Negative cycles: Edges may have negative weights. Bellman-Ford, Warshall


4. Strongly connected components: cycles. Tarjan, Kosaraju
5. Travelling salesman: Shortest path such that visits every city exactly once and returns to original city. Held-Karp, branch-and-bound, etc.


6. Minimum spanning tree: Combination of edges such that no cycles, minimum possible total edge weight. Kruskal, Prim, Borukva


7.Maxx network flow: how much quantity can be moved across the graph assuming some source and sink of infinite capacity for the quantity? Ford-Fulkerson, Edmonds-Karp, Dinic