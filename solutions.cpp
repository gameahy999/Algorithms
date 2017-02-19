#include <stdio.h>
#include <stdlib.h>

#include "binaryTree.h"
#include "util.h"


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

}


/* 338. Counting Bits */

static int
getNumberOf1(int n)
{
    int count = 0;

    while (n) {
        count++;
        n = (n-1) & n;
    }

    return count;
}

/*
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *
countBits(int num, int* returnSize)
{
    int *ret = NULL;

    if (num < 0) return NULL;

    ret = (int *)malloc((num + 1) * sizeof(int));
    for (int i = 0; i <= num; i++) {
        ret[i] = getNumberOf1(i);
    }

    *returnSize = num + 1;

    return ret;
}

void
test_countBits()
{
    int length = 0;
    int *output = countBits(5, &length);
    util::printIntArray(output, length);
    free(output);
}


/* 491. Increasing Subsequences */

/* Given an integer array, your task is to find all the different possible increasing subsequences of the given array, and the length of an increasing subsequence should be at least 2 .

Example:

Input: [4, 6, 7, 7]
Output: [[4, 6], [4, 7], [4, 6, 7], [4, 6, 7, 7], [6, 7], [6, 7, 7], [7,7], [4,7,7]]

Note:

1.The length of the given array will not exceed 15.
2.The range of integer in the given array is [-100,100].
3.The given array may contain duplicates, and two equal integers should also be considered as a special case of increasing sequence.

Subscribe to see which companies asked this question.
*/

/*
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int**
findSubsequences(int* nums, int numsSize, int** columnSizes, int* returnSize)
{
    return NULL;
}


/* 496. Next Greater Element I  */

/* You are given two arrays (without duplicates) nums1 and nums2 where nums1’s elements are subset of nums2. Find all the next greater numbers for nums1's elements in the corresponding places of nums2.

The Next Greater Number of a number x in nums1 is the first greater number to its right in nums2. If it does not exist, output -1 for this number.

Example 1:

Input: nums1 = [4,1,2], nums2 = [1,3,4,2].
Output: [-1,3,-1]
Explanation:
    For number 4 in the first array, you cannot find the next greater number for it in the second array, so output -1.
    For number 1 in the first array, the next greater number for it in the second array is 3.
    For number 2 in the first array, there is no next greater number for it in the second array, so output -1.



Example 2:

Input: nums1 = [2,4], nums2 = [1,2,3,4].
Output: [3,-1]
Explanation:
    For number 2 in the first array, the next greater number for it in the second array is 3.
    For number 4 in the first array, there is no next greater number for it in the second array, so output -1.



Note:

1.All elements in nums1 and nums2 are unique.
2.The length of both nums1 and nums2 would not exceed 1000.
*/

/*
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int*
nextGreaterElement(int* findNums, int findNumsSize, int* nums, int numsSize, int* returnSize)
{
    return NULL;
}
