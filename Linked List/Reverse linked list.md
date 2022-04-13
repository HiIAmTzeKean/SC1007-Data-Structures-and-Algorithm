# Reverse linked list

```c
Node* reverse(Node head)
{
    Node* reverseLL(Node *head)
    pre=fwd=NULL;
    cur=head;
    while (cur)
    {
        fwd=cur->next;
        cur->next=pre;
        pre=cur;
        cur=fwd;
    }
    return prev;
}
```
