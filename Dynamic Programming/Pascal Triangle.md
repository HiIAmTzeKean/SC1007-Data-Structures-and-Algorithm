# Pascal triangle

The question can be found on [Pascal Triangle](https://leetcode.com/problems/pascals-triangle/)

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int* returnSize, int** returnColumnSizes)
{
    // Create array to be returned
    int ** res = malloc(numRows*sizeof(int*));

    // Set parameters to be passed back
    *returnColumnSizes = malloc(numRows*sizeof(int*));
    *returnSize = numRows;

    for (int i = 0; i < numRows; i++) {
        // Create row to be filled
        res[i] = malloc((i+1)*sizeof(int));

        // Corner of row is always 1
        res[i][0] = res[i][i] = 1;
        (*returnColumnSizes)[i] = i+1;
        
        // Sum every 2 sequential col
        for (int j = 1; j < i; j++) res[i][j] = res[i-1][j-1] + res[i-1][j];
    }
    return res;
}
```
