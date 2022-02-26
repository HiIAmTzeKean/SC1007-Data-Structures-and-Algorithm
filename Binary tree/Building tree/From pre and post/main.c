#include <stdio.h>
#include <stdlib.h>

#define MAX_N 120

typedef struct _btnode{
    char id;
    struct _btnode *left;
    struct _btnode *right;
} BTNode;

void buildTree(BTNode** node, char* preO, char* postO);
void inOrder(BTNode *cur);
void preOrder(BTNode *cur);
void postOrder(BTNode *cur);

int main()
{
    char preO[MAX_N];
    char postO[MAX_N];
    scanf("%s",preO);
    scanf("%s",postO);

    BTNode* root=NULL;
    buildTree(&root,preO,postO);
    if(root==NULL) printf("error\n");
    preOrder(root);
    printf("\n");
    postOrder(root);
    printf("\n");

    inOrder(root);
    printf("\n");

    return 0;
}
void inOrder(BTNode *cur){
    if (cur == NULL)
        return;

    inOrder(cur->left);
    printf("%c",cur->id);
    inOrder(cur->right);
}
void preOrder(BTNode *cur){
    if (cur == NULL)
        return;

    printf("%c",cur->id);
    preOrder(cur->left);
    preOrder(cur->right);
}
void postOrder(BTNode *cur){
    if (cur == NULL)
        return;

    postOrder(cur->left);
    postOrder(cur->right);
    printf("%c",cur->id);
}
/*
124567389
564729831
*/

int sizeofstring(char *exp)
{
    int size=0;
    for (size;exp[size]!='\0';size++) {}
    return size;
}
void buildTree(BTNode** node, char* preO, char* postO)
{
    BTNode *lsub=NULL,*rsub=NULL,*newnode;
    char preLO[120],preRO[120];
    char postLO[120],postRO[120];
    int i=0,j=0,k=0;

    if (sizeofstring(preO)==1)
    {
        newnode=malloc(sizeof(BTNode));//insert as leaf
        newnode->id=preO[0];
        newnode->left=NULL;
        newnode->right=NULL;
        *node=newnode;
        return;
    }
    if (sizeofstring(preO)==2)
    {
        newnode=malloc(sizeof(BTNode));//insert as root
        newnode->id=preO[0];
        newnode->left=NULL;newnode->right=NULL;
        *node=newnode;
        newnode=malloc(sizeof(BTNode));
        newnode->id=preO[1];
        newnode->left=NULL;newnode->right=NULL;
        (*node)->left=newnode;
        return;
    }
    if (sizeofstring(preO)==3)
    {
        newnode=malloc(sizeof(BTNode));//insert as root
        newnode->id=preO[0];
        newnode->left=NULL;newnode->right=NULL;
        *node=newnode;
        //check if same order
        //if same order, insert right and left
        if (preO[1]==postO[0])
        {
            newnode=malloc(sizeof(BTNode));//insert as root
            newnode->id=preO[1];
            newnode->left=NULL;newnode->right=NULL;
            (*node)->left=newnode;
            newnode=malloc(sizeof(BTNode));
            newnode->id=preO[2];
            newnode->left=NULL;newnode->right=NULL;
            (*node)->right=newnode;
        }
        //else insert conseq left
        else
        {
            newnode=malloc(sizeof(BTNode));//insert as root
            newnode->id=preO[1];
            newnode->left=NULL;newnode->right=NULL;
            (*node)->left=newnode;
            lsub=malloc(sizeof(BTNode));//insert as root
            lsub->id=preO[2];
            lsub->left=NULL;lsub->right=NULL;
            newnode->left=lsub;
        }
        return;
    }

    //root=preO[0]
    //leftsub=preO[1], rightsub=postO[-2]
    while (postO[i]!=preO[1])
    {
        postLO[i]=postO[i];i++;
    }
    postLO[i++]=postO[i];
    postLO[i]='\0';
    while (postO[i]!=preO[0])
    {
        postRO[j]=postO[i]; i++;j++;
    }
    postRO[j]='\0';
    //right root=postRO[j-1]
    i=1;k=0;
    while (preO[i]!=postRO[j-1])
    {
        preLO[k++]=preO[i];i++;
    }
    preLO[k]='\0';
    k=0;
    while (preO[i]!='\0')
    {
        preRO[k]=preO[i];i++;k++;
    }
    preRO[k]='\0';
    //puts(preLO);
    //puts(postLO);
    //puts(preRO);
    //puts(postRO);
    if (preLO[0]!='\0')
        buildTree(&lsub,preLO,postLO);
    if (preRO[0]!='\0')
        buildTree(&rsub,preRO,postRO);
    (*node)=malloc(sizeof(BTNode));
    (*node)->left=lsub;
    (*node)->right=rsub;
    (*node)->id=preO[0];
}
