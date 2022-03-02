We assume that the circular linked list points back to head and not any other node

```
int checkCircular(Node *head)
{
    Node *temp=head;
    if (head==NULL)
        return 1;

    // We perform 2 checks
    // if temp is NULL, then it is not circular
    // if temp is head again, then it must be circular
    while (temp!=NULL && temp!=head)
        temp=temp->next;

    if (temp==NULL)
        return 0;
    else
        return 1;
}
```