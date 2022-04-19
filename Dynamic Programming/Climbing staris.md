# Climbing stairs

The question can be found on [climbing stairs](https://leetcode.com/problems/climbing-stairs/)

You are climbing a staircase. It takes n steps to reach the top. Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?  

## Dynamic programming solution

What we can do is to use an array to store the optimal solution for each step n, and progressively fill the array bottom up.

```c
int climbStairs(int n)
{
    // use memoization by keeping array
    int i;
    int arr[n+1];
    arr[0]=arr[1]=1;
    for (i=2;i<=n;i++)
        arr[i]=arr[i-1]+arr[i-2];
    return arr[n];
}
```

## Dynamic programming efficient

The more efficient approach is to use a smaller size array of 2. Since we can use
$$n=(n-1)+(n-2)$$
to calculate the solution for n, then only the 2 preceding n needs to be stored to obtain the solution.

```c
int climbStairs(int n)
{
    // use memoization by keeping array
    int arr[2];
    arr[0]=arr[1]=1;
    for (int i=2;i<=n;i++)
    {
        // formula is such that n=(n-1)+(n-2)
        // then we need a temp to hold value of (n-1) which becomes the next (n-2)
        int temp=arr[1];
        // update value of n for this cycle
        // and this value will be (n-1) for next cycle
        arr[1]=arr[1]+arr[0];
        // update value of (n-1) for this cycle
        // which becomes (n-2) for next cycle
        arr[0]=temp;
    }
    return arr[1];
}
```
