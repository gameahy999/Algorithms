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
