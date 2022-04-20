# Time complexity of simple graph search

## BFS

### Case of adjacency list

![adjacency list img](Adjacency%20list.jpg)

Since we use a queue structure to do the level traversal, then we must first consider the time complexity it takes to enqueue and dequeue. The graph has V vertices and if we assume that we keep track of visited vertices and enqueue/ dequeue take $O(n)$ time, total time for queue operations is $O(V)$. As for the edges of each vertex, BFS will scan each edge in the vertex to enqueue the child vertex, so the total time complexity will be $O(E)$, because total edges for adjacency list must be $\theta(E)$.

Total run time for BFS using adjacency list will be $O(V+E)$.

### Case of adjacency matrix

![adjacency mat img](Adjacency%20matrix.jpg)

Using the same idea, we have V vertices and for each vertex, we must scan for existing edges. But to check if edge exist for a adjacency matrix, we must iterate the whole row size V. So the check on each vertex takes $\theta(V)$ and the total time for V vertices will be $O(V^2)$

Total run time for BFS using adjacency matrix will be $O(V^2)$.

## DFS

![]()

Copyright &copy; 2022 Ng Tze Kean, Github @HiIAmTzeKean
