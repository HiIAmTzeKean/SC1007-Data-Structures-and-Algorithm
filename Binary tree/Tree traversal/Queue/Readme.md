Performing Bredth First Search (BFS) with Queue.

```
void BFS(BTNode *root)
{
    BTNode *currNode;
    Queue myqueue;
    myqueue.size=0;

    if (root==NULL) return;
    enqueue(&myqueue,root);
    while (!isEmptyQueue(myqueue))
    {
        currNode=getFront(myqueue);
        dequeue(&myqueue);
        printf("%d ",currNode->item);
        if (currNode->left)
            enqueue(&myqueue,currNode->left);
        if (currNode->right)
            enqueue(&myqueue,currNode->right);
    }
}
```