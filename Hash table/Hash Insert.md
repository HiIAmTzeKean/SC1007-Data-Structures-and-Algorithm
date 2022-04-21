# Hash insert

```c
int Hash(int key,int hSize);

ListNode* HashSearch(HashTable Q3Hash, int key)
{
    // Closed addressing search
    // Perform sanity check first
    if (Q3Hash->hSize<=0)
        return NULL;

    // Get the head of the linked list
    ListNode *curr=Q3Hash.Table[Hash(key, Q3Hash.hSize)].head;

    // iterate over the linked list to obtain nodes
    while (curr!=NULL)
    {
        if (curr.key==key)
            return curr;
        curr=curr->next;
    }
    return NULL;
}

int HashInsert(HashTable* Q3HashPtr, int key)
{
    // Perform duplicate check first
    if (HashSearch(*Q3HashPtr,key)!=NULL)
        return 0;
    
    // Perform sanity check if table is of valid size
    if (Q3Hash->hSize<=0)
        return 0;
    
    // insert into hash slot as front
    ListNode *newnode=malloc(sizeof(ListNode));
    newnode->key=key;

    int hashValue=Hash(key,Q3HashPtr->hSize);
    newnode->next=Q3Hash->Table[hashValue].head;
    Q3Hash->Table[hashValue].head=newnode;

    //increment table values
    Q3Hash->nSize++;
    Q3Hash->Table[hashValue].size++;
}
```
