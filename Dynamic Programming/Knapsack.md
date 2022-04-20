# Knapsack

Naive approach to solve the problem will mean for each item we can choose to keep it or to not keep it. For N items, we then have $O(2^n)$ time complexity.

## Knapsack DP

Time complexity reduce to $O(items*capacity)$. This is because for each item, we will fill the different possible weights from 1 to capacity.

```c
int knapsack(int items, int capacity, int *size, int *value)
{
    int array[items+1][capacity+1];

    // build the array from the smallest index of item
    // till we reach the largest index
    for (int i=0;i<=items;i++)
    {
        // iterate for a given weight j
        // decide if we should use the item or to not use it
        for (int j=0;j<=capacity;j++)
        {
            //if fill-in the boarder of array
            if (j==0 || i==0) {array[i][j]=0;continue;}

            //if the weight of current index exceed current allow weight
            //take the optimised value from the row above
            if (size[i]>j)
                array[i][j]=array[i-1][j];
            else
                //left is decision to use
                //right is decision to not use
                array[i][j]=max(array[i-1][j-size[i]]+value[i],array[i-1][j]);
        }
    }
    return array[items][capacity];
}
```

## Knapsack trace

Here we see the algo to trace the items that are taken in the sack. We create another 2D array to store the flag to indicate if the item is being used or not.

```c
int knapsack_trace(int items, int capacity, int *size, int *value)
{
    int array[items+1][capacity+1];
    int trace[items+1][capacity+1];

    // build the array from the smallest index of item
    // till we reach the largest index
    for (int i=0;i<=items;i++)
    {
        // iterate for a given weight j
        // decide if we should use the item or to not use it
        for (int j=0;j<=capacity;j++)
        {
            //if fill-in the boarder of array
            if (j==0 || i==0) {array[i][j]=trace[i][j]=0;continue;}

            //default values
            array[i][j]=array[i-1][j];
            trace[i][j]=0;
            
            //if the weight of current index exceed current allow weight
            //take the optimised value from the row above
            if (size[i]>j)
                continue;

            if (array[i-1][j-size[i]]+value[i]>array[i-1][j])
            {
                array[i][j]=array[i-1][j-size[i]]+value[i];
                //set the trace to be 1
                //indicating that we are using the current item
                trace[i][j]=1;
            }

        }
    }
    // print the trace
    int weight=capacity;
    int index=items;
    while (weight!=0)
    {
        //if item is used, print it
        //and decrement the weight
        if (trace[index][weight]==1)
        {
            printf("Item %d is used\n",index);
            weight-=size[index];
        }
        //else check the next item
        index--;
    }
    printf("\n");
    return array[items][capacity];
}
```

Copyright © 2022 Ng Tze Kean, Github @HiIAmTzeKean
