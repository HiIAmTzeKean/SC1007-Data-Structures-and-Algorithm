# Graph colouring

## Check if solution exist

With given number of colour m and a graph, we want to know if a solution exist. Then the following algo will return a boolean value which indicates if a solution can exist and the array will contain the solution. With backtracking implemented we incur time complexity $O(m^V)$ but because we prune the tree when there is no possible solution, we the algo is still faster than naive approach.

```c
int graphColoring(int graph[V][V], int m, int i,
                   int color[V])
{
    if (i==V)
        return 1;
    for (int j=1;j<=m;j++)
    {
        if (isSafe(i,graph,color,j))
        {
            //assign next colour
            color[i]=j;
            if (graphColoring(graph,m,i+1,color)) return 1;
            color[i]=0;
        }
    }
    return 0;
}
```

## Count number of possible solutions

```c
int graphColoring_Count(int graph[V][V], int m, int i, int color[V])
{
    if (i==V)
    {
        count+=1;
        return 1;
    }
    for (int j=1;j<=m;j++)
    {
        if (isSafe(i,graph,color,j))
        {
            //assign next colour
            color[i]=j;
            graphColoring_Count(graph,m,i+1,color);
            color[i]=0;
        }
    }
    return count;
}
```

Refer to the code below for the isSafe check

```c
int isSafe(int index, int graph[V][V], int color[], int c)
{
    for (int i=0;i<V;i++)
        if (graph[index][i] && c == color[i])
            return 0;
    return 1;
}
```

Copyright © 2022 Ng Tze Kean, Github @HiIAmTzeKean
