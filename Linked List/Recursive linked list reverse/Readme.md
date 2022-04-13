```
Node* reverseLL(Node *head)
{
    if (head==NULL)
        return NULL;
    if (head->next==NULL)
        return head;
    Node* cur=reverseLL(head->next);
    head->next->next=cur;
    head->next=NULL;
    return cur;
}
```