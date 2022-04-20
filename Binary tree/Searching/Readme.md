Find smallest value in tree

```c
int smallestValue(BTNode *node){
    int L,R;
    L=R=node->item;
    if (node->left)
        L=smallestValue(node->left);
    if (node->right)
        R=smallestValue(node->left);
    
    if (L<R && L<node->item)
        return L;
    else if (R<L && R<node->item)
        return R;
    else return node->item;
}
```
