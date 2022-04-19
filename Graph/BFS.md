# BFS algo

## Printing path travelled by BFS

We will use a queue to allow us to do a level order traversal. Below is the code that performs the search, note that we use an array g.visited to keep track of the nodes visited before.

```c
void BFS(Graph g, int v){
    Queue q;
    q.size=0;
    //start point is v
    enqueue(&q,v-1);
    g.visited[v-1]=1;
    while (!isEmptyQueue(q))
    {
        int curr=getFront(q);
        printf("%d ",curr+1);
        dequeue(&q);
        for (int i=0;i<g.V;i++)
        {
            if (g.visited[i]!=1 && g.matrix[curr][i]==1)
            {
                enqueue(&q,i);g.visited[i]=1;
            }
        }
    }
}
```

## Printing shortest path by BFS

The same idea is applied where we keep track of the parent nodes during the search. Once the goal node is found, we stop the search and iteratively print the parent nodes.

```c
int findpath_BFS(Graph g, int start, int goal)
{
    Queue q;
    q.size=0;
    int found=0;
    
    // Place starting node in the queue to being search
    enqueue(&q,start-1);
    // use visited as the list to store the parent node
    // We indicate the root of the breadth spanning tree
    // to be -1
    g.visited[start-1]=-1;
    
    while (!isEmptyQueue(q))
    {
        int curr=getFront(q);
        dequeue(&q);
        if (curr==goal-1)
            {found=1;break;}
        for (int i=0;i<g.V;i++)
        {
            if (g.visited[i]==0 && g.matrix[curr][i]==1)
            {
                enqueue(&q,i);g.visited[i]=curr+1;
            }
        }
    }

    // A path does not exist and thus we return a
    // 0 flag and end the function
    if (!found)
        return 0;
        
    // print the solution given by BFS
    int temp=goal;
    while (temp!=-1)
    {
        printf("%d ",temp);
        temp=g.visited[temp-1];
    }
    return 1;

    /*
    // if you need to print it from start to goal node
    // then this would be the algo to use
    ListNode *head=malloc(sizeof(ListNode));
    head->next=NULL;
    int temp=goal;
    while (temp!=-1)
    {
        ListNode *newnode=malloc(sizeof(ListNode));
        newnode->vertex=temp;
        newnode->next=head->next;
        head->next=newnode;
        temp=g.visited[temp-1];
    }
    head=head->next;
    while (head!=NULL)
    {
        printf("%d ",head->vertex);
        head=head->next;
    }
    return 1;
    */
}
```

For more information about the data structures used, please refer below

```c
typedef struct _listnode
{
    int vertex;
    struct _listnode *next;
} ListNode;

typedef struct _graph{
    int V;
    int E;
    int *visited;
    int **matrix;
}Graph;

typedef ListNode QueueNode;

typedef struct _queue{
   int size;
   QueueNode *head;
   QueueNode *tail;
} Queue;
```
