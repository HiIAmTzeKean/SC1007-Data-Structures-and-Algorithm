# DFS algo

## Print out depth traversal

There are many ways we can perform the depth traversal, the simplest is to do a recursive call and perform the traversal.

```c
void DFS_R(Graph g, int v)
{
    g.visited[v-1]=1;
    printf("%d ", v);
    for (int i=0;i<g.V;i++)
    {
        if (g.matrix[v-1][i]==1 && g.visited[i]==0)
            DFS_R(g,i+1);
    }
}
```

## Return DFS path

To return a path done by DFS. The function below will populate the visited array with the next successor in the depth spanning tree. The start node will have the next successor and we just need to iterate till goal node is reached.

```c
int DFS_R_path(Graph g, int v, int goal)
{
    g.visited[v-1]=1;
    if (v==goal) return 1;
    for (int i=0;i<g.V;i++)
    {
        if (g.matrix[v-1][i]==1 && g.visited[i]==0)
        {
            g.visited[v-1]=i+1;
            for(int j=0;j<g.V;j++) printf("%d ",g.visited[j]);
            puts("");
            if (DFS_R_path(g,i+1,goal)==1)
                {g.visited[v-1]=i+1; return 1;}
        }
    }
    return 0;
}
```
