# Recover Binary Search

The question can be found here [Recover Binary Search Tree](https://leetcode.com/problems/recover-binary-search-tree/)

Can be done with a stack to perform inorder traversal to make it a cleaner solution, but recursion works here as well.  
By travelling the tree inorder, we are forcing the check to be in ascending order, numbers that do not comply to this rule are numbers out of place. We set 2 address to keep these 2 problem nodes, and 2 pointers to keep track of the previous and current value.

Note: this solution can be done without cur pointer, it is used to make the solution readable

```c
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void inorder(struct TreeNode* root,struct TreeNode** p1,struct TreeNode** p2,struct TreeNode** prev,struct TreeNode** cur)
{
    if (root==NULL) return;
    
    if (root->left)
        inorder(root->left,p1,p2,prev,cur);

    if (*prev==NULL)
        *prev=*cur=root;
    else
    {
        *cur=root;
        if ((*prev)->val>(*cur)->val)
        {
            if (*p1==NULL)
            {
                *p1=*prev;*p2=*cur;
            }
            else
                *p2=*cur;
           
        }
        *prev=*cur;
    }
    
    if (root->right)
        inorder(root->right,p1,p2,prev,cur);
}

void recoverTree(struct TreeNode* root)
{
    struct TreeNode *p1=NULL, *p2=NULL;
    struct TreeNode *prev=NULL, *cur=NULL;
    inorder(root,&p1,&p2,&prev,&cur);
    int temp=p1->val;
    p1->val=p2->val;
    p2->val=temp;
}
```

Copyright © 2022 Ng Tze Kean, Github @HiIAmTzeKean
