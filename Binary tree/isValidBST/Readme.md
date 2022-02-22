Checking if Binary tree is valid.

Poor example:
```
int isBST(BTNode *root)
{
    int flag=0;
    if (root==NULL) return 1; //empty tree is valid
    
    if (root->left!=NULL && root->left->item > root->item) //check immediate left node is less than
        return 0;
        
    if (root->right!=NULL && root->right->item < root->item) //check immediate right node is more than
        return 0;

    return isBST(root->left) && isBST(root->right);
}
```

Good example:
