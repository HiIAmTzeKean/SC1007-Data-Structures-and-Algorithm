Given a pre-order and post-order sequence, we create a tree out of it.  

Assumptions:  
1. No duplicate nodes
2. No memory constrains since we will be utilising arrays to store the sequence

Test case:  
124567389  
564729831

Output:  
546271983

```
void buildTree(BTNode** node, char* preO, char* postO)
{
    int i=0,j=0;
    char LpostO[120], RpostO[120], LpreO[120], RpreO[120];
    
    // Base cases for recursion
    // If the string length is 1, meaning only 1 digit
    // Insert as leaf
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
    
    // If the above 2 cases not fulfilled, we continue traversing
    // We note that first char of preO is the root
    // Second char of preO is left child
    // Last char of postO is root
    // Second last char of postO is right child
    while (postO[i]!=preO[1])
        LpostO[i++]=postO[i];
    LpostO[i++]=postO[i];
    LpostO[i]='\0';

    while (postO[i]!=preO[0])
        RpostO[j++]=postO[i++];
    RpostO[j]='\0';
    
    // Since the left subtree is a set with no duplicates
    // number of elements is left preO must be same in left postO
    for(i=0;LpostO[i]!='\0';i++)
        LpreO[i]=preO[i+1];
    LpreO[i++]='\0';
    j=0;
    while (preO[i]!='\0')
        RpreO[j++]=preO[i++];
    RpreO[j]='\0';
    
    // We create the root node here
    // and call the function to create left and right subtree
    (*node)=malloc(sizeof(BTNode));
    (*node)->id=preO[0];
    (*node)->left=(*node)->right=NULL;
    if (LpreO[0]!='\0')
        buildTree(&(*node)->left,LpreO,LpostO);
    if (RpreO[0]!='\0')
        buildTree(&(*node)->right,RpreO,RpostO);
}
```