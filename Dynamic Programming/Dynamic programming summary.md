# Dynamic programming summary

For some function that we can solve recursively, we tend to incur repeated costs. The idea of top-down solution is to break one problem into smaller problems, but for cases like fibonacci, we are repeatedly solving the same sub-problems when n is large.

For fibonacci recursive, $$f(n)=f(n-1)+f(n-2)$$ then solving the problem would mean each node will have 2 child nodes, less the leaf nodes. The time complexity would be $O(2^n)$.

If we create an array to store the preceding computed values, then each unique value of fibonacci only needs to be computed once. Time complexity will be $O(n)$. This technique is known as memoization.

## DP in general

Can be applied to solve sub-problems that are dependent on each other by caching the solution in an array. Do note that DP only returns 1 of the many optimal solutions possible. This is unlike [backtracking](../Backtracking/Backtracking%20summary.md) which traces each possible solution. The idea behind DP is speed in obtaining one solution.

DP can be applied top-down or bottom-up. Bottom-up technique is typically more efficient than top-down solution, but is harder to derive and formulate compared to top-down approach.

Copyright © 2022 Ng Tze Kean, Github @HiIAmTzeKean
