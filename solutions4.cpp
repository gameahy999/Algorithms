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

/* Implementations for problem 400 ~ 499 */

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
removeKdigits(char *num, int k)
{
    return NULL;
}

void
test_removeKdigits()
{

}


/* 404. Sum of Left Leaves */

/* Find the sum of all left leaves in a given binary tree.

Example:

    3
   / \
  9  20
    /  \
   15   7

There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24.
*/

int
sumOfLeftLeaves(struct TreeNode* root)
{
    if (root == NULL) return 0;
    if (root->left && root->left->left == NULL && root->left->right == NULL) {
        return root->left->val + sumOfLeftLeaves(root->right);
    } else {
        return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
    }
}

void
test_sumOfLeftLeaves()
{
    TreeNode *root = new TreeNode(3);
    TreeNode *node1 = new TreeNode(9);
    TreeNode *node2 = new TreeNode(20);
    TreeNode *node3 = new TreeNode(15);
    TreeNode *node4 = new TreeNode(7);
    root->left = node1;
    root->right = node2;
    node2->left = node3;
    node2->right = node4;
    printf("%d\n", sumOfLeftLeaves(root));
    delete root;
    delete node1;
    delete node2;
    delete node3;
    delete node4;
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
splitArray(int *nums, int numsSize, int m)
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
findAnagrams(char *s, char *p, int *returnSize)
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


/* 442. Find All Duplicates in an Array */

/* Given an array of integers, 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.

Find all the elements that appear twice in this array.

Could you do it without extra space and in O(n) runtime?

Example:

Input:
[4,3,2,7,8,2,3,1]

Output:
[2,3]
*/

int *
findDuplicates(int *nums, int numsSize, int *returnSize)
{
    // TODO: to make it meet the space requirement.
    *returnSize = 0;
    if (nums == NULL || numsSize <= 0) return NULL;

    int *data = (int *)malloc(numsSize * sizeof(int));
    int *ret = (int *)malloc(numsSize * sizeof(int));
    memset(data, 0, numsSize * sizeof(int));

    for (int i = 0; i < numsSize; i++) {
        data[nums[i] - 1]++;
    }

    int index = 0;
    for (int i = 0; i < numsSize; i++) {
        if (data[i] > 1) {
            ret[index++] = i + 1;
            (*returnSize)++;
        }
    }

    free(data);
    return ret;
}

void
test_findDuplicates()
{
    int nums[8] = {4, 3, 2, 7, 8, 2, 3, 1};
    int len = 0;
    int *output = findDuplicates(nums, 8, &len);
    util::printIntArray(output, len);
    free(output);
}


/* 448. Find All Numbers Disappeared in an Array */

/* Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.

Find all the elements of [1, n] inclusive that do not appear in this array.

Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.

Example:
Input:
[4,3,2,7,8,2,3,1]

Output:
[5,6]

*/

/*
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *
findDisappearedNumbers(int *nums, int numsSize, int *returnSize)
{
    if (nums == NULL || numsSize == 0) return NULL;

    int *ret = (int *)malloc(numsSize * sizeof(int));
    for (int i = 0; i < numsSize; i++) {
        int tmp = abs(nums[i]);
        nums[tmp - 1] = -abs(nums[tmp - 1]); // Perfect!
    }

    int index = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > 0) {
            ret[index++] = i + 1;
        }
    }

    *returnSize = index;
    return ret;
}

void
test_findDisappearedNumbers()
{
    int nums[8] = {4, 3, 2, 7, 8, 2, 3, 1};
    int returnSize = 0;
    int *output = findDisappearedNumbers(nums, 8, &returnSize);
    util::printIntArray(output, returnSize);
    free(output);
}


/* 451. Sort Characters By Frequency*/

/* Given a string, sort it in decreasing order based on the frequency of characters.

Example 1:

Input:
"tree"

Output:
"eert"

Explanation:
'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.

Example 2:

Input:
"cccaaa"

Output:
"cccaaa"

Explanation:
Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
Note that "cacaca" is incorrect, as the same characters must be together.

Example 3:

Input:
"Aabb"

Output:
"bbAa"

Explanation:
"bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.
*/

char *
frequencySort(char *s)
{
    // TODO
    return NULL;
}

void
test_frequencySort()
{

}


/* 453. Minimum Moves to Equal Array Elements */

/* Given a non-empty integer array of size n, find the minimum number of moves required to make all array elements equal, where a move is incrementing n - 1 elements by 1.

Example:

Input:
[1,2,3]

Output:
3

Explanation:
Only three moves are needed (remember each move increments two elements):

[1,2,3]  =>  [2,3,3]  =>  [3,4,3]  =>  [4,4,4]
*/

int
minMoves(int *nums, int numsSize)
{
    // TODO
    return 0;
}

void
test_minMoves()
{

}


/* 455. Assign Cookies */

/*  Assume you are an awesome parent and want to give your children some cookies. But, you should give each child at most one cookie. Each child i has a greed factor gi, which is the minimum size of a cookie that the child will be content with; and each cookie j has a size sj. If sj >= gi, we can assign the cookie j to the child i, and the child i will be content. Your goal is to maximize the number of your content children and output the maximum number.

Note:
You may assume the greed factor is always positive.
You cannot assign more than one cookie to one child.

Example 1:

Input: [1,2,3], [1,1]

Output: 1

Explanation: You have 3 children and 2 cookies. The greed factors of 3 children are 1, 2, 3.
And even though you have 2 cookies, since their size is both 1, you could only make the child whose greed factor is 1 content.
You need to output 1.

Example 2:

Input: [1,2], [1,2,3]

Output: 2

Explanation: You have 2 children and 3 cookies. The greed factors of 2 children are 1, 2.
You have 3 cookies and their sizes are big enough to gratify all of the children,
You need to output 2.
*/

int
findContentChildren(int *g, int gSize, int *s, int sSize)
{
    // TODO
    return 0;
}

void
test_findContentChildren()
{

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


/* 485. Max Consecutive Ones */

/* Given a binary array, find the maximum number of consecutive 1s in this array.

Example 1:

Input: [1,1,0,1,1,1]
Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s.
    The maximum number of consecutive 1s is 3.

Note:
•The input array will only contain 0 and 1.
•The length of input array is a positive integer and will not exceed 10,000
*/

int
findMaxConsecutiveOnes(int *nums, int numsSize)
{
    int max = 0;
    int count = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == 1) {
            count++;
        } else {
            if (count > max) {
                max = count;
            }
            count = 0;
        }
    }
    return max > count ? max : count; // easy to make mistakes in this problem
}

void
test_findMaxConsecutiveOnes()
{
    int nums[6] = {1, 1, 0, 1, 1, 1};
    printf("%d\n", findMaxConsecutiveOnes(nums, 6));
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
int **
findSubsequences(int *nums, int numsSize, int **columnSizes, int *returnSize)
{
    return NULL;
}


/* 492. Construct the Rectangle */

/* For a web developer, it is very important to know how to design a web page's size. So, given a specific rectangular web page’s area, your job by now is to design a rectangular web page, whose length L and width W satisfy the following requirements:
1. The area of the rectangular web page you designed must equal to the given target area.

2. The width W should not be larger than the length L, which means L >= W.

3. The difference between length L and width W should be as small as possible.

You need to output the length L and the width W of the web page you designed in sequence.

Example:

Input: 4
Output: [2, 2]
Explanation: The target area is 4, and all the possible ways to construct it are [1,4], [2,2], [4,1].
But according to requirement 2, [1,4] is illegal; according to requirement 3,  [4,1] is not optimal compared to [2,2]. So the length L is 2, and the width W is 2.

Note:

1.The given area won't exceed 10,000,000 and is a positive integer
2.The web page's width and length you designed must be positive integers.
*/

/*
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *
constructRectangle(int area, int *returnSize)
{
    int *ret = (int *)malloc(2 * sizeof(int));
    int l = sqrt(area), w = sqrt(area);

    while (l * w != area) {
        if (l * w < area) {
            l++;
        } else {
            w--;
        }
    }
    ret[0] = l;
    ret[1] = w;

    *returnSize = 2;
    return ret;
}

void
test_constructRectangle()
{
    int count = 0;
    int *ret = constructRectangle(4, &count);
    util::printIntArray(ret, count);
    free(ret);
}


/* 495. Teemo Attacking */

/*  In LLP world, there is a hero called Teemo and his attacking can make his enemy Ashe be in poisoned condition. Now, given the Teemo's attacking ascending time series towards Ashe and the poisoning time duration per Teemo's attacking, you need to output the total time that Ashe is in poisoned condition.

You may assume that Teemo attacks at the very beginning of a specific time point, and makes Ashe be in poisoned condition immediately.

Example 1:

Input: [1,4], 2
Output: 4
Explanation: At time point 1, Teemo starts attacking Ashe and makes Ashe be poisoned immediately.
This poisoned status will last 2 seconds until the end of time point 2.
And at time point 4, Teemo attacks Ashe again, and causes Ashe to be in poisoned status for another 2 seconds.
So you finally need to output 4.

Example 2:

Input: [1,2], 2
Output: 3
Explanation: At time point 1, Teemo starts attacking Ashe and makes Ashe be poisoned.
This poisoned status will last 2 seconds until the end of time point 2.
However, at the beginning of time point 2, Teemo attacks Ashe again who is already in poisoned status.
Since the poisoned status won't add up together, though the second poisoning attack will still work at time point 2, it will stop at the end of time point 3.
So you finally need to output 3.

Note:

    You may assume the length of given time series array won't exceed 10000.
    You may assume the numbers in the Teemo's attacking time series and his poisoning time duration per attacking are non-negative integers, which won't exceed 10,000,000.
*/

int
findPoisonedDuration(int *timeSeries, int timeSeriesSize, int duration)
{
    if (timeSeries == NULL || timeSeriesSize <= 0) return 0;

    int count = 0;
    for (int i = 0; i < timeSeriesSize - 1; i++) {
        int current = timeSeries[i];
        int next = timeSeries[i + 1];
        if (current + duration <= next) {
            count += duration;
        } else {
            count += (next - current);
        }
    }
    count += duration; // This is for the last element.
    return count;
}

void
test_findPoisonedDuration()
{
    int time_array1[2] = {1, 4};
    printf("%d\n", findPoisonedDuration(time_array1, 2, 2));

    util::printDelimiter();

    int time_array2[2] = {1, 2};
    printf("%d\n", findPoisonedDuration(time_array2, 2, 2));

    util::printDelimiter();

    printf("%d\n", findPoisonedDuration(NULL, 0, 10000));
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
nextGreaterElement(int *findNums, int findNumsSize, int *nums, int numsSize, int *returnSize)
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
