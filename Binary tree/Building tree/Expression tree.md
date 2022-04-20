# Expression tree

Given a pre-order and in-order sequence, we create a tree out of it.  

Assumptions:

1. No duplicate nodes
2. No memory constrains since we will be utilising arrays to store the sequence

Test case:  
124567389  
546271983

Output:  
564729831  

```c
void buildTree(BTNode** node, char* preO, char* inO)
{
    int i=0,j=0;
    char LinO[120], RinO[120], LpreO[120], RpreO[120];

    if (sizeofstring(preO)==1)
    {
        *node=malloc(sizeof(BTNode));
        (*node)->id=preO[0];
        (*node)->left=(*node)->right=NULL;
        return;
    }
    // If there is 2, it means one is the left child of the other
    else if (sizeofstring(preO)==2)
    {
        *node=malloc(sizeof(BTNode));
        (*node)->id=preO[0];
        (*node)->right=NULL;
        (*node)->left=malloc(sizeof(BTNode));
        (*node)->left->id=preO[1];
        (*node)->left->left=(*node)->left->right=NULL;
        return;
    }

    // The left side of root node in in-order is left subtree
    // Right side of root node in in-order is right subtree
    while (inO[i]!=preO[0])
        LinO[i++]=inO[i];
    LinO[i++]='\0';
    while (inO[i]!='\0')
        RinO[j++]=inO[i++];
    RinO[j]='\0';

    // Number of elements in left subtree of preorder and inorder must be same
    for (i=0;LinO[i]!='\0';i++)
        LpreO[i]=preO[i+1];
    LpreO[i++]='\0';
    j=0;
    while (preO[i]!='\0')
        RpreO[j++]=preO[i++];
    RpreO[j]='\0';

    (*node)=malloc(sizeof(BTNode));
    (*node)->id=preO[0];
    (*node)->left=(*node)->right=NULL;
    if (LpreO[0]!='\0')
        buildTree(&(*node)->left,LpreO,LinO);
    if (RpreO[0]!='\0')
        buildTree(&(*node)->right,RpreO,RinO);
}
```
