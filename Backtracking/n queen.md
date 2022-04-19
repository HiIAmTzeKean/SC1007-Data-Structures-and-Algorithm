# n queen problem

Assume isSafe function is established for now. We create a function that counts the number of possible complete solution.

```c
int count=0;
int nQueen(int **board, int n, int c)
{
    if (n==c) return 1;
    
    for (int i=0;i<n;i++)
    {
        if (isSafe())
        {
            // If safe try every other combination
            // Set queen on board first
            board[i][c]=1;
            count+=nQueen();
            // Clear board before backtracking
            board[i][c]=0;
        }
    }
    return 0;
}
```

Refer to isSafe function here. The function checks if the current column violates any of the constraints by testing if the queen placed at the current row and col will attack any of the other queen in col[0:current-1].

```c
int isSafe(int **board, int n, int c, int r)
{
    // Check horizontal
    for (int i=0,i<c;i++)
        if (board[r][c]==1) return 0;
    // Check diagonal
    for(int i=0;i<n;i++)
    {
        if(row+i<n && col-i>-1)
            if(board[row+i][col-i]) return 0;
        if(row-i>-1 && col-i>-1)
            if(board[row-i][col-i]) return 0;
    }
    return 1;
}
```
