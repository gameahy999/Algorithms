#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>
#include <vector>
#include <string>

#include "binaryTree.h"
#include "search.h"
#include "sort.h"
#include "util.h"

using namespace std;

/* Implementations for problem 200 ~ 299 */

/* 226. Invert Binary Tree */

/*
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode*
invertTree(struct TreeNode* root)
{
    // Implemented in binaryTree.cpp file.
    return invertBinaryTree(root);
}

void test_invertTree()
{
    // Have already been tested in OJ
}


/* 283. Move Zeroes */

/* Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].

Note:

1.You must do this in-place without making a copy of the array.
2.Minimize the total number of operations.
*/

void
moveZeroes(int *nums, int numsSize)
{
    if (nums == NULL || numsSize == 0) return;

    int index = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == 0) {
            continue;
        } else {
            nums[index++] = nums[i];
        }
    }

    for (int i = index; i < numsSize; i++) {
        nums[i] = 0;
    }

    return;
}

void
test_moveZeros()
{
    int a[5] = {0, 1, 0, 3, 12};
    moveZeroes(a, 5);
    util::printIntArray(a, 5);
}


/* 292. Nim Game */

/* You are playing the following Nim Game with your friend: There is a heap of stones on the table, each time one of you take turns to remove 1 to 3 stones. The one who removes the last stone will be the winner. You will take the first turn to remove the stones.

Both of you are very clever and have optimal strategies for the game. Write a function to determine whether you can win the game given the number of stones in the heap.

For example, if there are 4 stones in the heap, then you will never win the game: no matter 1, 2, or 3 stones you remove, the last stone will always be removed by your friend.
*/

bool
canWinNim(int n)
{
    return (n % 4 != 0);
}

void
test_canWinNim()
{
    util::printBool(canWinNim(4));
    util::printBool(canWinNim(5));
    util::printBool(canWinNim(6));
    util::printBool(canWinNim(7));
    util::printBool(canWinNim(1348820612));
}
