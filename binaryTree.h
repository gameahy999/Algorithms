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

TreeNode *constructBinaryTree(int *preorder, int *inorder, int length);
void destructBinaryTree(TreeNode **ppRoot);


typedef void (*TreeNodeVisitFunc)(TreeNode *node);

void preorderTraverseBinaryTree_Iteratively(TreeNode *root, TreeNodeVisitFunc func);
void inorderTraverseBinaryTree_Iteratively(TreeNode *root, TreeNodeVisitFunc func);
void postorderTraverseBinaryTree_Iteratively(TreeNode *root, TreeNodeVisitFunc func);

void preorderTraverseBinaryTree_Recursively(TreeNode *root, TreeNodeVisitFunc func);
void inorderTraverseBinaryTree_Recursively(TreeNode *root, TreeNodeVisitFunc func);
void postorderTraverseBinaryTree_Recursively(TreeNode *root, TreeNodeVisitFunc func);

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
