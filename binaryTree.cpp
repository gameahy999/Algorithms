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
    // int rootValue = startPreorder[0];
    // TreeNode *root = new TreeNode(rootValue);

    // if (startPreorder == endPreorder) {
    //     if (startInorder == endInorder &&
    //         *startPreorder == *startInorder) {
    //         return root;
    //     } else {
    //         throw std::exception("Invalid input.");
    //     }
    // }

    // int rootInorder = startInorder;
    // while (rootInorder <= endInorder && *rootInorder != rootValue) {
    //     rootInorder++;
    // }

    // if (rootInorder == endInorder && *rootInorder != rootValue) {
    //     throw std::exception("Invalid input");
    // }

    // int leftLength = rootInorder - startInorder;
    // int *leftPreorderEnd = startPreorder + leftLength;
    // if (leftLength > 0) {
    //     root->left = constructBinaryTreeCore(startPreorder + 1,
    //                                          leftPreorderEnd,
    //                                          startInorder,
    //                                          rootInorder - 1);
    // }
    // if (leftLength < endPreorder - startPreorder) {
    //     root->right = constructBinaryTreeCore(leftPreorderEnd + 1,
    //                                           endPreorder,
    //                                           rootInorder + 1,
    //                                           endInorder);
    // }

    // return root;
    return NULL;
}


TreeNode *
constructBinaryTree(int *preorder, int *inorder, int length)
{
    if (preorder == NULL || inorder == NULL || length <= 0) {
        return NULL;
    }

    return constructBinaryTreeCore(preorder, preorder + length - 1,
                                   inorder, inorder + length - 1);
}


void
destructBinaryTree(TreeNode **ppRoot) /* IN/OUT */
{
    // if (ppRoot == NULL || *ppRoot == NULL) return;

    // destructBinaryTree(&(*ppRoot->left));
    // destructBinaryTree(&(*ppRoot->right));

    // delete *ppRoot;
    // *ppRoot = NULL;
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
