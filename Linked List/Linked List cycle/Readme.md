[Linked List Cycle II](https://leetcode.com/problems/linked-list-cycle-ii/)

```
struct ListNode *detectCycle(struct ListNode *head)
{
    struct ListNode *p1,*p2;
    p1=p2=head;
    while (p2!=NULL && p2->next!=NULL)
    {
        p1=p1->next;
        p2=p2->next->next;
        if (p1==p2)
        {
            // At this point p1 travelled distance (X) head to start of cycle
            // and distance (Y) start of cycle to meet up point
            p1=head;
            // p2 on the other hand must travel twice the distance of p1
            // thus from meet up point, if we add (X+Y) to position p2 again, 
            // we will arrive at the same point
            //            <X>                <Y>
            // head -------------circle---------------meet up -|
            //                      |---------------------------
            //                               <X>
            while (p1!=p2)
            {
                // we set p1 to be head and let p1 and p2 travel by 1 unit
                // they will travel distance X to start of circle
                p1=p1->next;
                p2=p2->next;
            }
            return p1;
        }
    }
    return NULL;
}
```