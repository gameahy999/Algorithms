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
