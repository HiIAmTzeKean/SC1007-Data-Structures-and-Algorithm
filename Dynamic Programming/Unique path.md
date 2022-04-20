# Unique path

The question can be found on [Unique Path](https://leetcode.com/problems/unique-paths/)

Robot that can only move down or right.
Solved with memoization

```c
int **table;
int uniquePaths(int m, int n)
{
    table=malloc(m*sizeof(int*));
    for (int i=0;i<m;i++) table[i]=calloc(n,sizeof(int));
    int temp=helper(m,n);
    free(table);
    return temp;
}

int helper(int m, int n)
{
    // Breaking down the program into smaller square for each move
    // Base condition
    if (m<1 || n<1) return 0;
    if (m==1 || n==1)
    {
        table[m-1][n-1]=1;
        return 1;
    }
    // Check if the distance is in the array
    // if the preceding info is not in array, memoize
    if (!table[m-2][n-1]) table[m-2][n-1]=helper(m-1,n);
    if (!table[m-1][n-2]) table[m-1][n-2]=helper(m,n-1);
    
    return table[m-1][n-1]=table[m-2][n-1]+table[m-1][n-2];
}
```

Copyright © 2022 Ng Tze Kean, Github @HiIAmTzeKean
