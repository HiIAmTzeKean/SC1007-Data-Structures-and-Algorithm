We use a stack to traverse the tree in a non-recursive manner when we are restricted from using recursive loops. Stack will be used to hold the nodes that we need to to travel to, or have travelled to. Stacks are utilised to perform Depth First Search (DFS), Queues are used for Breadth First Search (BFS).

We define the stack in such a manner
```
typedef struct _stacknode
{
    struct _stacknode *next;
    int item;
} stackNode;
typedef struct _stack
{
    stackNode *head;
    int size;
} Stack;
```

I am assuming you have your utility functions for your stack. Useful utilities we will use are push, pop, peek, and isEmpty. The code below demonstrate how we can traverse the tree using the stack in a similar fashion to our recursive calls.

1. Stack with pre-order
```
void preorder(BTNode *root)
{
    BTNode *curr=root;
    Stack traversal;
    //sanity check
    if (root==NULL) return;
    push(&traversal,root)
    while (!isEmptyStack(traversal))
    {
        // Obtain the parent node
        curr=pop(&traversal);
        // Perform operations on parent first
        printf(curr->item);
        // Push right in first so that we traverse the left side
        // Left child will be top most node in stack
        if (curr->right)
            push(&traversal,curr->right);
        if (curr->left)
            push(&traversal,curr->left);
        // Move pointer to the left child and continue travel
        // If left was NULL, pointer will move to right child
    }
}
```

2. Stack with in-order
```
void inorder(BTNode *root)
{
    BTNode *curr;
    Stack traveral;
    if (root==NULL) return;
    while (curr!=NULL)
    {
        if (curr->left)
        {
            push(&traveral,curr);
            curr=curr->left;
        }
        else if (curr->right)
        {
            printf("%d ",curr->item);
            curr=curr->right;
        }
        else
        {
            while (!isEmptyStack(traveral) && curr->right==NULL)
            {
                printf("%d ",curr->item);
                curr=peek(traveral);
                pop(&traveral);
            }
            printf("%d ",curr->item);
            curr=curr->right;
        }
    }
}
```

[geeksforgeeks solution](https://www.geeksforgeeks.org/inorder-tree-traversal-without-recursion/) in C program
```
void inorder(BTNode *root)
{
    BTNode *curr=root;
    Stack traversal;
    while (1)
    {
        // We always push to stack whenever there is a left node
        if (curr!=NULL)
        {
            push(&traversal,curr);
            curr=curr->left;
        }
        // Consider case when there is no left node
        // Pop from stack, and get its right child
        // If right child is NULL, we continue moving up till we have no more nodes
        else
        {
            if (!isEmptyStack(traversal))
            {
                curr=pop(&traversal);
                printf("%d ",curr->item);
                curr=curr->right;
            }
            else return;
        }
    }
}
```

3. Stack with post-order
```
void postOrderIterative(BTNode *root)
{
    BTNode *curr=root;
    Stack traversal;
    traversal.size=0;
    while (1)
    {
        if (curr!=NULL)
        {
            if (curr->right)
                push(&traversal,curr->right);
            push(&traversal,curr);
            curr=curr->left;
        }
        else
        {
            // End of traversal condition
            if (isEmptyStack(traversal))
                return;

            curr=peek(traversal);
            pop(&traversal);
            // We check if the the item on top of the stack is right child of current node
            // if it is, we swap the nodes such that we are now in the right child
            if (!isEmptyStack(traversal) && curr->right==peek(traversal))
            {
                pop(&traversal);
                push(&traversal,curr);
                curr=curr->right;
            }
            // If there is no valid right child, the node must not have any other nodes on its right
            // We print it and set pointer to null so that we can get the next node on the next iteration
            else
            {
                printf("%d ",curr->item);
                curr=NULL;
            }
        }
    }
}
```

[geeksforgeeks solution](https://www.geeksforgeeks.org/iterative-postorder-traversal-using-stack/) in C program
```
void postOrderIterative(struct Node* root)
{
    Stack traversal;
    // Sanity check
    if (root==NULL) return;

    do
    {
        // Move to leftmost node
        while (root)
        {
            // Push root's right child and then root to stack.
            if (root->right)
                push(traversal,root->right);
            push(traversal,root);
 
            // Set root as root's left child
            root=root->left;
        }
 
        // Pop an item from stack and set it as root    
        root = pop(traversal);
 
        // If the popped item has a right child and the right child is not
        // processed yet, then make sure right child is processed before root
        if (root->right && peek(traversal)==root->right)
        {
            pop(traversal); // remove right child from stack
            push(traversal, root); // push root back to stack
            root = root->right; // change root so that the right
                                // child is processed next
        }
        else // Else print root's data and set root as NULL
        {
            printf("%d ",root->data);
            root=NULL;
        }
    } while (!isEmpty(traversal));
}
```