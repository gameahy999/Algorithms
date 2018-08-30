#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>
#include <vector>
#include <string>

#include "binaryTree.h"
#include "linkedList.h"
#include "search.h"
#include "sort.h"
#include "util.h"

using namespace std;

/* Implementations for problem 0 ~ 99 */

/* 1. Two Sum */

/* Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].

*/

void
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


/* 2. Add Two Numbers */

static int
singleDigitAdd(ListNode *pNodeA, ListNode *pNodeB, int lastCarry)
{
    int sum = lastCarry;
    if (pNodeA) sum += pNodeA->val;
    if (pNodeB) sum += pNodeB->val;
    return sum >= 10 ? sum - 10 : sum;
}

static int
calculateCarry(ListNode *pNodeA, ListNode *pNodeB, int lastCarry)
{
    int sum = lastCarry;
    if (pNodeA) sum += pNodeA->val;
    if (pNodeB) sum += pNodeB->val;
    return sum >= 10 ? 1 : 0;
}

ListNode *
addTwoNumbers(ListNode* l1, ListNode* l2)
{
    ListNode *pNode = NULL, *pHead = NULL;
    int carry = 0;

    while (l1 != NULL || l2 != NULL || carry != 0) {
        if (pHead == NULL) {
            pHead = new ListNode(singleDigitAdd(l1, l2, carry));
            pNode = pHead;
            carry = calculateCarry(l1, l2, carry);
        } else {
            pNode->next = new ListNode(singleDigitAdd(l1, l2, carry));
            pNode = pNode->next;
            carry = calculateCarry(l1, l2, carry);
        }

        if (l1) l1 = l1->next;
        if (l2) l2 = l2->next;
    }

    return pHead;
}

void
test_addTwoNumbers()
{
    ListNode *l1 = generateIntLinkedList(3, 2, 4, 3);
    ListNode *l2 = generateIntLinkedList(3, 5, 6, 4);
    printIntLinkedList(addTwoNumbers(l1, l2));

    ListNode *l3 = generateIntLinkedList(2, 1, 8);
    ListNode *l4 = generateIntLinkedList(1, 0);
    printIntLinkedList(addTwoNumbers(l3, l4));

    ListNode *l5 = generateIntLinkedList(1, 5);
    ListNode *l6 = generateIntLinkedList(1, 5);
    printIntLinkedList(addTwoNumbers(l5, l6));
}


/* 9. Palindrome Number */

static void
int2DigitArray(int x, int *digits, int *length)
{
    int index = 0;
    *length = 0;

    while (x != 0) {
        digits[index] = x % 10;
        x = x / 10;
        index++;
        (*length)++;
    }
}

bool
isPalindrome(int x)
{
    if (x < 0) return false;

    int digits[16] = {0};
    int length = 0;
    int2DigitArray(x, digits, &length);

    int head = 0, tail = length - 1;
    bool result = true;

    while (head < tail) {
        if (digits[head] != digits[tail]) {
            result = false;
            break;
        }

        head++;
        tail--;
    }

    return result;
}

void
test_isPalindrome()
{
    cout << isPalindrome(121) << endl;
    cout << isPalindrome(-121) << endl;
    cout << isPalindrome(10) << endl;
}


/* 33. Search in Rotated Sorted Array */

/* Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.
*/

int
search(int *nums, int numsSize, int target)
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

/*
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

int *
grayCode(int n, int *returnSize)
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
