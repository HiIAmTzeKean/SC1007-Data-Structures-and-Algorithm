# For loop analysis

## Single for loop analysis

Simple for loop time complexity. Then the instruction is executed N times, thus $O(n)$

```c
for (int i=0;i<n;i++)
        some O(1) instruction;
```

If we take a step further, then we can see that if the code below is executed, then for each iteration, N instructions is executed. Thus $O(n^2)$ time needed for the loop.

```c
for (int i=0;i<n;i++)
        some O(N) instruction;
```

## Nested loop analysis

The code below will run in $O(n^2)$. The outer loop will run N times, and the inner loop run N times as well. Then we can see that time complexity must be the product of outer and inner loop

```c
for (int i=0;i<n;i++)
    for (int j=0;j<n;j++)
        some O(1) instruction;
```

A less intuitive calculation will follow the code below. Then for each iteration of the outer loop, the inner loop will have a decreasing run time of 1. The calculation will be as follows $$(n-1)+(n-2)+(n-3)...2+1$$ Applying arithmetic sum on the equation, we get $$\frac{n-1}{2}(1+n-1)=\frac{n^2-n}{2}=O(n^2)$$

```c
for (int i=0;i<n;i++)
    for (int j=i+1;j<n;j++)
        some O(1) instruction;
```

By forward induction, we can logically prove the same for a 3 nested for loop time complexity. And as expected, the time complexity in this case is $O(n^3)$

```c
for (int i=0;i<n;i++)
    for (int j=i+1;j<n;j++)
        for (int k=i+1;k<n;k++)
                some O(1) instruction;
```

---

References:

- <https://www.enjoyalgorithms.com/blog/time-complexity-analysis-of-loop-in-programming>
