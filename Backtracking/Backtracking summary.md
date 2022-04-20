# Backtracking summary

Given a problem and we want to find all possible solutions/ permutations, we can apply backtracking to count the number of possible solutions.

## Simple pseudocode

```
initialise solution count as global variable

backtrack(n)
{
    if (n is goal)
        return success
    else
        return fail
    
    for each possible assignment in n
        if backtrack(n) is success
            increment solution count
}
```

## Time complexity

Given the colouring problem, of n colours with V possible nodes. If we check if each combination is valid, we must iterate $n^V$ combinations since node can hold colour 0~n.

Given the n queen problem, where board is n×n size. If we check if each combination is valid, we must iterate $n\times n \choose n$ combinations since we must decide how we want to. Even if we optimised the bruteforce to $n!$, because each column can only hold one queen, we are still incurring a high time complexity.

Thus, backtracking can be used to reduce the cost of the search by pruning nodes that have already violated the constraints.

Copyright © 2022 Ng Tze Kean, Github @HiIAmTzeKean
