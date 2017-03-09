#ifndef _BINARY_TREE_H_
#define _BINARY_TREE_H_

/*
 *------------------------------------------------------------------------------
 *
 * Normal binary tree.
 *
 *------------------------------------------------------------------------------
 */

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void printBinaryTree(TreeNode *root);
TreeNode *generateFullBinaryTree();
TreeNode *invertBinaryTree(TreeNode *root);

/*
 *------------------------------------------------------------------------------
 *
 * These interfaces below are only used for binary search tree.
 *
 *------------------------------------------------------------------------------
 */

int getMaxElementOfBinarySearchTree(TreeNode *root);
int getMinElementOfBinarySearchTree(TreeNode *root);

#endif
