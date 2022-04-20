# Cut rod problem

## Simple recursive

Though the recursive method, we can solve the problem by iterating through each unit length to check if we should cut or to not cut. This is a binary choice, so for each unit length we then have 2 choices. For n length, we have $O(2^n)$ time complexity.

```c
int cr_recursive(int *p, int n)
{
    //base case
    if (n==0) return 0;
    if (n==1) return 1;

    int temp=-1;
    for (int i=1;i<=n;i++)
        //find if using rod n gives max or if using
        //n-1 gives max
        temp=max(temp,cr_recursive(p,n-i)+p[i]);
    return temp;
}
```

## Dynamic programming approach

Here we apply DP to solve the problem to reduce time complexity. By finding the optimal length for the sub-problem, if we encounter the same problem again, we can fetch the solution from memory. Then we see that for length n, we have time complexity $O(n^2)$.

```c
int *r; // array we use to memoize
int cr_top_down_dp(int *p, int n)
{
    //base case
    if (n==0) return 0;
    if (n==1) return 1;
    if (r[n]!=-1) return r[n];

    int temp=-1;
    for (int i=1;i<=n;i++)
    {
        temp=max(temp,cr_top_down_dp(p,n-i)+p[i]);
        r[n]=temp;
    }
    return r[n];
}
```

Here we prove the time complexity. For each iteration i of the outer for loop, we will have the iterate the inner loop by 1 count more. Hence when i=2, inner loop runs 2 times. Applying induction, we have i=n, inner loop runs n times. Mathematically we have
$$1+2+3+...+(n-1)+n$$
Apply arithmetic series,
$$\frac{n}{2}(n+1)=O(n^2)$$

```c
int cr_bottom_up_dp(int *p, int n)
{
    r[0]=0;
    r[1]=1;
    for (int i=2;i<=n;i++)
    {
        r[i]=p[i];
        for (int j=1;j<=i;j++)
        {
            //i is current rod len
            //j is the factor to iterate to check combination
            r[i]=max(r[i],r[i-j]+r[j]);
        }
    }
    return r[n];
}
```

## Trace optimal solution

To obtain the rods that we have used, simply create another array to store the rod length it is to be cut to.

```c
int *r;
int cr_bottom_up_dp_print(int *p, int n)
{
    int trace[n+1];
    trace[0]=r[0]=0;
    trace[1]=r[1]=1;

    for (int i=2;i<=n;i++)
    {
        r[i]=p[i];
        trace[i]=i;
        for (int j=1;j<i;j++)
        {
            if (r[i]<r[i-j]+r[j])
            {
                r[i]=r[i-j]+r[j];
                trace[i]=i-j;
            }
        }
    }
    int temp=n;
    printf("Length of each piece is:\n");
    while (temp!=0)
    {
        printf("%d ", trace[temp]);
        temp-=trace[temp];
    }
    printf("\n");
    return r[n];
}
```

Copyright © 2022 Ng Tze Kean, Github @HiIAmTzeKean
