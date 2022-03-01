Question from (LeetCode)[https://leetcode.com/problems/binary-tree-right-side-view/]

Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

```
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int max(int n1, int n2) {
    return n1 > n2 ? n1 : n2;
}

int dfs(struct TreeNode* root, int *nodes, int index) {
    if (root == NULL) return 0;
    
    if (nodes[index] == -101)
        nodes[index] = root->val;

    // We always try to travel to right first
    // If right is NULL, we 
    int size = dfs(root->right, nodes, index + 1);
    // Get the deeper depth and add 1 to its depth to account for current node
    size = max(dfs(root->left, nodes, index + 1), size) +1;
    return size;
}

int* rightSideView(struct TreeNode* root, int* returnSize){
    // create array to store the values
    int *nodes = malloc(sizeof(int) * 100);
    
    // set each element of array to be outside valid value of node
    for (int i = 0; i < 100; ++i) nodes[i] = -101;
    
    // return size of array
    *returnSize = dfs(root, nodes, 0);
    return nodes;
}
```