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

#define DEBUG printf
// #define DEBUG fake_printf
void fake_printf(const char *format,...) {}

// TODO: Devide this big file into five separate files in future.
// solutions.cpp  ~ problems   1 -  99
// solutions1.cpp ~ problems 100 - 199
// solutions2.cpp ~ problems 200 - 299
// solutions3.cpp ~ problems 300 - 399
// solutions4.cpp ~ problems 400 - 499
// solutions5.cpp ~ problems 500 - 599

/* 1. Two Sum */

/* Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].

*/

int
twoSum(int *data, int length, int target)
{
    int begin = 0;
    int end = length - 1;

    quickSort(data, begin, end);

    while (begin < end) {
        long currSum = data[begin] + data[end];

        if (currSum == target) {
            printf("%d %d\n", data[begin], data[end]);

            // add the two statements below if outputing all pairs is required.
            // begin++;
            // end--;
            break;
        } else {
            if (currSum < target)
                begin++;
            else
                end--;
        }
    }
}

void
test_twoSum()
{
    int a[6] = {1, 2, 4, 7, 11, 15};
    twoSum(a, 6, 15);
}


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


/* 344. Reverse String */

/* Write a function that takes a string as input and returns the string reversed.

Example:
 Given s = "hello", return "olleh".
*/

char *
reverseString(char *s)
{
    if (s == NULL || strlen(s) <= 1) return s;

    int len = strlen(s);
    int head = 0, tail = len - 1;
    while (tail > head) {
        util::swapChar(s + tail, s + head);
        tail--;
        head++;
    }
    return s;
}

void
test_reverseString()
{
    char tmp[10];
    strcpy(tmp, "hello");
    printf("%s\n", reverseString(tmp));
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


/* 412. Fizz Buzz */

/*Write a program that outputs the string representation of numbers from 1 to n.

But for multiples of three it should output “Fizz” instead of the number and for the multiples of five output “Buzz”. For numbers which are multiples of both three and five output “FizzBuzz”.

Example:
n = 15,

Return:
[
    "1",
    "2",
    "Fizz",
    "4",
    "Buzz",
    "Fizz",
    "7",
    "8",
    "Fizz",
    "Buzz",
    "11",
    "Fizz",
    "13",
    "14",
    "FizzBuzz"
]

*/

vector<string>
fizzBuzz(int n)
{
    std::vector<string> v;
    char buf[10] = {0};
    for (int i = 1; i <= n; i++) {
        string str = "";
        bool specialString = false;
        if (i % 3 == 0) {
            str += (string("Fizz"));
            specialString = true;
        }
        if (i % 5 == 0) {
            str += (string("Buzz"));
            specialString = true;
        }
        if (!specialString) {
            itoa(i, buf, 10);
            // With C++ 11 support, we can simply use to_string(i) instead.
            str += (string(buf));
        }
        v.push_back(str);
    }

    return v;
}

void
test_fizzBuzz()
{
    std::vector<string> v = fizzBuzz(15);
    for (vector<string>::iterator iter = v.begin(); iter != v.end(); iter++) {
        cout << *iter << endl;
    }
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

static bool
charMapEqual(int *s, int *p)
{
    bool ret = true;
    for (int i = 0; i < 26; i++) {
        if (s[i] != p[i]) {
            ret = false;
            break;
        }
    }

    return ret;
}

static void
initializeCharMap(int *charMap, char *input, int len)
{
    if (charMap == NULL) return;
    for (int i = 0; i < len; i++) {
        charMap[input[i] - 'a']++;
    }
}

int *
findAnagrams(char* s, char* p, int* returnSize)
{
    if (s == NULL) return NULL;

    int len_s = strlen(s);
    int len_p = strlen(p);
    if (len_s < len_p) return NULL;

    int *ret = (int *)malloc(len_s * sizeof(int));
    int stringSCharMap[26] = {0};
    int stringPCharMap[26] = {0};

    initializeCharMap(stringPCharMap, p, len_p);
    initializeCharMap(stringSCharMap, s, len_p);

    *returnSize = 0;
    int index = 0;
    for (int i = 0; i <= len_s - len_p; i++) {
        if (charMapEqual(stringSCharMap, stringPCharMap)) {
            ret[index++] = i;
            (*returnSize)++;
        }

        if (s[i + len_p] - 'a' >= 0) {
            stringSCharMap[s[i] - 'a']--;
            stringSCharMap[s[i + len_p] - 'a']++;
        }
    }

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
    util::printIntArray(ret2, returnSize2);
    free(ret2);

    // s: "cbaebabacd" p: "abc"
    const char *s3 = "cbaebabacd";
    const char *p3 = "abc";
    int returnSize3 = 0;
    int *ret3 = findAnagrams(const_cast<char *>(s3),
                             const_cast<char *>(p3),
                             &returnSize3);
    util::printIntArray(ret2, returnSize3);
    free(ret3);
}


/* 461. Hamming Distance */

int
hammingDistance(int x, int y)
{
    int count = 0;
    int n = x ^ y;

    while (n) {
        n = (n - 1) & n;
        count++;
    }

    return count;
}

void
test_hammingDistance()
{
    printf("%d\n", hammingDistance(1, 4));
}


/* 463. Island Perimeter */

/* You are given a map in form of a two-dimensional integer grid where 1 represents land and 0 represents water. Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells). The island doesn't have "lakes" (water inside that isn't connected to the water around the island). One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.

Example:
[[0,1,0,0],
 [1,1,1,0],
 [0,1,0,0],
 [1,1,0,0]]

Answer: 16

*/

static int
getGridElement(const std::vector<vector<int> >& grid,
               int row,
               int rowSize,
               int col,
               int colSize)
{
    if (row < 0 || col < 0 || row >= rowSize || col >= colSize) return 0;
    return grid[row][col];
}

int islandPerimeter(vector<vector<int> >& grid)
{
    int row = grid.size();
    if (row == 0) return 0;

    int col = grid[0].size();
    int ret = 0;

    for (int i = -1; i < row; i++) {
        for (int j = -1; j < col; j++) {
            ret += abs(getGridElement(grid, i + 1, row, j, col) -
                       getGridElement(grid, i, row, j, col));
            ret += abs(getGridElement(grid, i, row, j + 1, col) -
                       getGridElement(grid, i, row, j, col));
        }
    }
    return ret;
}

void
test_islandPerimeter()
{
    int grid[16] = {0, 1, 0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 1, 1, 0, 0};
    vector<vector<int> > v;
    std::vector<int> v0(&grid[0], &grid[3]);
    std::vector<int> v1(&grid[4], &grid[7]);
    std::vector<int> v2(&grid[8], &grid[11]);
    std::vector<int> v3(&grid[12], &grid[15]);
    v.push_back(v0);
    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);
    printf("%d\n", islandPerimeter(v));
}


/* 476. Number Complement */

/* Given a positive integer, output its complement number. The complement strategy is to flip the bits of its binary representation.

Note:

1.The given integer is guaranteed to fit within the range of a 32-bit signed integer.
2.You could assume no leading zero bit in the integer’s binary representation.

Example 1:

Input: 5
Output: 2
Explanation: The binary representation of 5 is 101 (no leading zero bits), and its complement is 010. So you need to output 2.

Example 2:

Input: 1
Output: 0
Explanation: The binary representation of 1 is 1 (no leading zero bits), and its complement is 0. So you need to output 0.
*/

int
findComplement(int num)
{
    int tmp = num;
    int mask = 1;

    while (tmp) {
        tmp >>= 1;
        mask <<= 1;
    }
    return (mask - 1) ^ num;
}

void
test_findComplement()
{
    printf("%d\n", findComplement(5));
    printf("%d\n", findComplement(1));
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

/* 500. Keyboard Row */

/* Example 1:

Input: ["Hello", "Alaska", "Dad", "Peace"]
Output: ["Alaska", "Dad"]

*/

vector<string>
findWords(vector<string>& words)
{
    // Row number for  A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z
    int charMap[26] = {2, 3, 3, 2, 1, 2, 2, 2, 1, 2, 2, 2, 3, 3, 1, 1, 1, 1, 2, 1, 1, 3, 1, 3, 1, 3};
    std::vector<string> svec;
    for (vector<string>::iterator iter = words.begin();
         iter != words.end();
         iter++) {
        if ((*iter).length() <= 1) {
            svec.push_back(*iter);
            continue;
        }

        int line = charMap[tolower((*iter)[0]) - 'a'];
        bool canTypeInOneRow = true;
        for (int i = 1; i < (*iter).length(); i++) {
            if (line != charMap[tolower((*iter)[i]) - 'a']) {
                canTypeInOneRow = false;
                break;
            }
        }
        if (canTypeInOneRow) {
            svec.push_back(*iter);
        }
    }

    return svec;
}

void
test_findWords()
{
    std::vector<string> v;
    v.push_back("Hello");
    v.push_back("Alaska");
    v.push_back("Dad");
    v.push_back("Peace");

    std::vector<string> v_output = findWords(v);
    for (vector<string>::iterator iter = v_output.begin();
         iter != v_output.end();
         iter++) {
        cout << *iter << endl;
    }
}
