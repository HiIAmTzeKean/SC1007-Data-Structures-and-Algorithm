For Pre-order recursive traversal

```
void preorder(Node *root):
    // We set base cause such that we return if we are not in a node
    if (root==NULL) return;

    // For preorder traversal, we always perform operation on node we are at before moving to the left
    // If there are no more valid left nodes, we then move up to the parent and to the right child of the parent
    printf("%d "root->item);
    preorder(root->left);
    preorder(root->right);
```

For In-order recursive traversal

```
void inorder(Node *root):
    // We set base cause such that we return if we are not in a node
    if (root==NULL) return;

    // For inorder traversal, we always traverse the left child till we reach the left most node
    // We perform operation on the left most child, then we move up to the root node and finally to right child of root
    inorder(root->left);
    printf("%d "root->item);
    inorder(root->right);
```

For Post-order recursive traversal

```
void postorder(Node *root):
    // We set base cause such that we return if we are not in a node
    if (root==NULL) return;

    // For postorder traversal, we always traverse the left child till we reach the left most node
    // We perform operation on the left most child, then to right child of parent
    // operation will be performed on parent last
    postorder(root->left);
    postorder(root->right);
    printf("%d "root->item);
```