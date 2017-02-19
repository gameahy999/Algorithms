#ifndef _BINARY_TREE_H_
#define _BINARY_TREE_H_

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void printBinaryTree(TreeNode *root);
TreeNode *generateFullBinaryTree();
TreeNode *invertBinaryTree(TreeNode *root);

#endif
