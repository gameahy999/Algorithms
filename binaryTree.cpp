#include <limits.h>
#include <stdio.h>

#include "binaryTree.h"


void
printBinaryTree(TreeNode *root)
{

}


// TODO
TreeNode *
generateFullBinaryTree()
{
    return NULL;
}


TreeNode *
invertBinaryTree(TreeNode *root)
{
    struct TreeNode *tmp = NULL;

    if (root == NULL) return root;
    if (root->left == NULL && root->right == NULL) return root;

    tmp = invertBinaryTree(root->left);
    root->left = invertBinaryTree(root->right);
    root->right = tmp;

    return root;
}


static TreeNode *
constructBinaryTreeCore(int *startPreorder,
                        int *endPreorder,
                        int *startInorder,
                        int *endInorder)
{
    // TODO
    return NULL;
}


TreeNode *
constructBinaryTree(int *preorder, int *inorder, int length)
{
    // TODO
    return NULL;
}


void
destructBinaryTree(TreeNode *root)
{

}


/*
 *------------------------------------------------------------------------------
 *
 * Interfaces to traverse a binary tree. Devide into iterative, recursive
 * and broad first traversal versions.
 *
 *------------------------------------------------------------------------------
 */

void
preorderTraverseBinaryTree_Iteratively(TreeNode *root, TreeNodeVisitFunc func)
{

}


void
inorderTraverseBinaryTree_Iteratively(TreeNode *root, TreeNodeVisitFunc func)
{

}


void
postorderTraverseBinaryTree_Iteratively(TreeNode *root, TreeNodeVisitFunc func)
{

}


void
preorderTraverseBinaryTree_Recursively(TreeNode *root, TreeNodeVisitFunc func)
{

}


void
inorderTraverseBinaryTree_Recursively(TreeNode *root, TreeNodeVisitFunc func)
{

}


void
postorderTraverseBinaryTree_Recursively(TreeNode *root, TreeNodeVisitFunc func)
{

}


void
broadFirstTraverseBinaryTree(TreeNode *root, TreeNodeVisitFunc func)
{

}


/*
 *------------------------------------------------------------------------------
 *
 * These interfaces below are only used for binary search tree.
 *
 *------------------------------------------------------------------------------
 */

int
getMaxElementOfBinarySearchTree(TreeNode *root)
{
    if (root == NULL) return INT_MIN + 1;

    TreeNode *tmp = root;
    while (tmp->right) {
        tmp = tmp->right;
    }
    return tmp->val;
}


int
getMinElementOfBinarySearchTree(TreeNode *root)
{
    if (root == NULL) return INT_MAX;

    TreeNode *tmp = root;
    while (tmp->left) {
        tmp = tmp->left;
    }
    return tmp->val;
}
