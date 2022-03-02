We detect that we are at leaf node when both pointers left and right are to NULL.

```
int sumOfLeaf(BTNode *root)
{
    if (root==NULL) return 0; // Sanity check
    // If condition is fulfilled, we are at root node
    if (root->left==NULL && root->right==NULL) return root->item;

    // Traverse the tree in pre-order fashion to obtain the sum of all
    // leaf nodes.
    return sumOfLeaf(root->left)+sumOfLeaf(root->right);
}
```