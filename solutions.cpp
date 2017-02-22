#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "binaryTree.h"
#include "search.h"
#include "util.h"


/* 33. Search in Rotated Sorted Array */

/* Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.
*/

int
search(int* nums, int numsSize, int target)
{
    return 0;
}

void
test_search()
{
    int nums[7] = {4, 5, 6, 7, 0, 1, 2};
    printf("%d\n", search(nums, 7, 6));
    printf("%d\n", search(nums, 7, 3));
}


/* 60. Permutation Sequence */

/* The set [1,2,3,…,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order,
 We get the following sequence (ie, for n = 3):
1."123"
2."132"
3."213"
4."231"
5."312"
6."321"


Given n and k, return the kth permutation sequence.

Note: Given n will be between 1 and 9 inclusive.
*/

char *
getPermutation(int n, int k)
{
    return NULL;
}

void
test_getPermutation()
{

}


/* 69. Sqrt(x) */

/* Implement int sqrt(int x).

Compute and return the square root of x.
*/

int
mySqrt(int x)
{
    return 0;
}

void
test_mySqrt()
{

}


/* 89. Gray Code */

/* The gray code is a binary numeral system where two successive values differ in only one bit.

Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.

For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:
00 - 0
01 - 1
11 - 3
10 - 2

Note:
 For a given n, a gray code sequence is not uniquely defined.

For example, [0,2,3,1] is also a valid gray code sequence according to the above definition.

For now, the judge is able to judge based on one instance of gray code sequence. Sorry about that.
*/

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

int *
grayCode(int n, int* returnSize)
{
    int *ret = NULL;

    *returnSize = 1 << n;
    ret = (int *)malloc(*returnSize * sizeof(int));
    for (int i = 0; i < *returnSize; i++) {
        // the ith gray code is (i >> 1) ^ i
        ret[i] = (i >> 1) ^ i;
    }

    return ret;
}

void
test_grayCode()
{
    int size = 0;
    int *output = grayCode(3, &size);
    util::printIntArray(output, size);
    free(output);
}


/* 149. Max Points on a Line */

/* Given n points on a 2D plane, find the maximum number
 * of points that lie on the same straight line.
 */

/*
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 * }
 */

int
maxPoints(struct Point* points, int pointsSize)
{
    return 0;
}

void
test_maxPoints()
{

}


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


/* 402. Remove K Digits */

/* Given a non-negative integer num represented as a string, remove k digits from the number so that the new number is the smallest possible.

Note:

•The length of num is less than 10002 and will be ≥ k.
•The given num does not contain any leading zero.

Example 1:
Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.

Example 2:
Input: num = "10200", k = 1
Output: "200"
Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.

Example 3:
Input: num = "10", k = 2
Output: "0"
Explanation: Remove all the digits from the number and it is left with nothing which is 0.

*/

char *
removeKdigits(char* num, int k)
{
    return NULL;
}

void
test_removeKdigits()
{

}


/* 410. Split Array Largest Sum */

/* Given an array which consists of non-negative integers and an integer m, you can split the array into m non-empty continuous subarrays. Write an algorithm to minimize the largest sum among these m subarrays.

Note:
 If n is the length of array, assume the following constraints are satisfied:
•1 ≤ n ≤ 1000
•1 ≤ m ≤ min(50, n)

Examples:
Input:
nums = [7,2,5,10,8]
m = 2

Output:
18

Explanation:
There are four ways to split nums into two subarrays.
The best way is to split it into [7,2,5] and [10,8],
where the largest sum among the two subarrays is only 18.
*/

int
splitArray(int* nums, int numsSize, int m)
{
    return 0;
}


/* 438. Find All Anagrams in a String */

/* Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.

Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.

The order of output does not matter.

Example 1:
Input:
s: "cbaebabacd" p: "abc"

Output:
[0, 6]

Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".

Example 2:
Input:
s: "abab" p: "ab"

Output:
[0, 1, 2]

Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".
*/

/*
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
void
replaceFirstSpecifiedChar(char *p, char src, char dst)
{
    if (p == NULL) return;
    int len = strlen(p);
    if (len == 0) return;

    for (int i = 0; i < len; i++) {
        if (p[i] == src) {
            p[i] = dst;
            break;
        }
    }
}

static bool
charInString(char a, const char *p)
{
    if (p == NULL) return false;
    int len = strlen(p);
    for (int i = 0; i < len; i++) {
        if (a == p[i]) {
            return true;
        }
    }
    return false;
}

static bool
stringMatch(char *s, char *p, int len)
{
    if (s == NULL || *s == '\0' || len <= 0) return true;
    if (strlen(s) < len) return false;
    if (!charInString(*s, p)) return false;
    else {
        replaceFirstSpecifiedChar(p, *s, '$');
        return stringMatch(s + 1, p, len - 1);
    }
}

// XXX: This is too slow, but a work version.
int *
findAnagrams(char* s, char* p, int* returnSize)
{
    int index = 0;
    int length = strlen(s);
    char tmp[100] = {0};

    if (length == 0) return NULL;

    int *ret = (int *)malloc(length * sizeof(int));

    for (int i = 0; i < length; i++) {
        strcpy(tmp, p);
        if (stringMatch(s + i, tmp, strlen(tmp))) {
            ret[index++] = i;
        }
    }

    *returnSize = index;
    return ret;
}

void
test_findAnagrams()
{
    // s: "cbaebabacd" p: "abc"
    const char *s1 = "cbaebabacd";
    const char *p1 = "abc";
    int returnSize1 = 0;
    int *ret1 = findAnagrams(const_cast<char *>(s1),
                             const_cast<char *>(p1),
                             &returnSize1);
    util::printIntArray(ret1, returnSize1);
    free(ret1);

    // s: "abab" p: "ab"
    const char *s2 = "abab";
    const char *p2 = "ab";
    int returnSize2 = 0;
    int *ret2 = findAnagrams(const_cast<char *>(s2),
                             const_cast<char *>(p2),
                             &returnSize2);
    util::printIntArray(ret1, returnSize2);
    free(ret2);
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
// TODO: create a seperate file contains find related algorithms.
// Actually, it's not quick now.
static int
quickfind(int *nums, int numsSize, int target)
{
    slowSearch(nums, numsSize, target);
}

int *
nextGreaterElement(int* findNums, int findNumsSize, int* nums, int numsSize, int* returnSize)
{
    *returnSize = findNumsSize;
    int *ret = (int *)malloc((*returnSize) * sizeof(int));

    for (int i = 0; i < findNumsSize; i++) {
        int index = quickfind(nums, numsSize, findNums[i]);
        ret[i] = -1;

        if (index >= numsSize - 1) continue;

        for (int j = index + 1; j < numsSize; j++) {
            if (nums[j] > findNums[i]) {
                ret[i] = nums[j];
                break;
            }
        }
    }
    return ret;
}

void
test_nextGreaterElement()
{
    // Input: nums1 = [4,1,2], nums2 = [1,3,4,2].
    // Output: [-1,3,-1]
    int nums1[3] = {4, 1, 2};
    int nums2[4] = {1, 3, 4, 2};
    int *ret = NULL;
    int returnSize = 0;

    ret = nextGreaterElement(nums1, 3, nums2, 4, &returnSize);
    util::printIntArray(ret, returnSize);
    free(ret);
    ret = NULL;

    // Input: nums1 = [2,4], nums2 = [1,2,3,4].
    // Output: [3,-1]
    int nums3[2] = {2, 4};
    int nums4[4] = {1, 2, 3, 4};
    ret = nextGreaterElement(nums3, 2, nums4, 4, &returnSize);
    util::printIntArray(ret, returnSize);
    free(ret);
    ret = NULL;
}
