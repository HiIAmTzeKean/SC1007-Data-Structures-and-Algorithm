# Minimum Depth of Binary Tree

The link to the question can be found here [Minimum Depth of Binary Tree](https://leetcode.com/problems/minimum-depth-of-binary-tree/)

```c
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int min(int a, int b)
    return a<b?a:b;

int minDepth(struct TreeNode* root)
{
    if (root==NULL) return 0;
    if (root->left==NULL && root->right==NULL) return 1;
    
    int L=minDepth(root->left);
    int R=minDepth(root->right);
    if (L!=0 && R!=0)
        return min(L,R)+1;
    else if (L)
        return L+1;
    return R+1;
}
```

Copyright © 2022 Ng Tze Kean, Github @HiIAmTzeKean
