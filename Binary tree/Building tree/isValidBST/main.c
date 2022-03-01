#include <stdio.h>
#include <stdlib.h>

typedef struct _btnode
{
    int item;
    struct _btnode *left;
    struct _btnode *right;
} BTNode;

int isvalid(BTNode *root)
{
    if (root == NULL)
        return 1;
    else if (root->left == NULL && root->right == NULL)
        return 1;

    if (root->left != NULL && (maxval(root->left) > root->item))
        return 0;

    if (root->right != NULL && (minval(root->right) < root->item))
        return 0;

    return isvalid(root->left) && isvalid(root->right);
}

int maxval(BTNode *root)
{
    int L, R;
    if (root == NULL)
        return NULL;
    if (root->left == NULL && root->right == NULL)
        return root->item;
    L = maxval(root->left);
    R = maxval(root->right);
    if (root->item > L && root->item > R)
        return root->item;
    if (L > root->item && L > R)
        return L;
    if (R > L && R > root->item)
        return R;
}

int minval(BTNode *root)
{
    int L, R;
    if (root == NULL)
        return NULL;
    if (root->left == NULL && root->right == NULL)
        return root->item;
    L = minval(root->left);
    R = minval(root->right);
    if (R == NULL)
    {
        if (root->item < L)
            return root->item;
        else
            return L;
    }
    if (L == NULL)
    {
        if (root->item < R)
            return root->item;
        else
            return R;
    }
    if (root->item < L && root->item < R)
        return root->item;
    if (L < root->item && L < R)
        return L;
    if (R < L && R < root->item)
        return R;
}