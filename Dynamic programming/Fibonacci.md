# Fibonacci

We can improve the runtime by using memoization, use of some data structure to hold values that were computed before to reduce redundant recursion in program

```c
int fib(int n)
{
    int *arr=malloc(sizeof(int)*(n+1));
    memset(arr,-1,(n+1)*sizeof(int));
    arr[0]=0;

    // Replace function you want to run here
    return dynamicProgram(n,arr);
}

int top_down(int n, int *arr)
{
    // Return the value of 
    if (n<=0) return 0;
    if (n==1 || n==2) return 1;
    if (arr[n]!=-1) return arr[n];

    if (arr[n-1]==-1)
        arr[n-1]=top_down(n-1,arr);
    if (arr[n-2]==-1)
        arr[n-2]=top_down(n-2,arr);
    
    return arr[n]=arr[n-1]+arr[n-2];
}

int bottom_up(int n, int *arr)
{
    arr[0]=0;
    arr[1]=arr[2]=1;

    // Fill the array with each value of the fibonacci value
    for (int i=3;i<=n;i++)
        arr[i]=arr[i-1]+arr[i-2];

    return arr[n];
}
```
