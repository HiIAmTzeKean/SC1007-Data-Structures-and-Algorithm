Using stack to traverse tree

we define the stack in such a manner
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

We can continue traversing with the 3 aforementioned methods

1. Stack with pre-order
'''
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
'''

2. Stack with in-order

My solution
'''
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
'''

geeksforgeeks solution
https://www.geeksforgeeks.org/inorder-tree-traversal-without-recursion/
'''
void inorder(BTNode *root)
{
    BTNode *curr=root;
    Stack mystack;
    while (1)
    {
        // We always push to stack whenever there is a left node
        if (curr!=NULL)
        {
            push(&mystack,curr);
            curr=curr->left;
        }
        // Consider case when there is no left node
        // Pop from stack, and get its right child
        // If right child is NULL, we continue moving up till we have no more nodes
        else
        {
            if (!isEmptyStack(mystack))
            {
                curr=pop(&mystack);
                printf("%d ",curr->item);
                curr=curr->right;
            }
            else return;
        }
    }
}
'''

3. Stack with post-order
'''
'''