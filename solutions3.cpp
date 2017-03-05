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

/* Implementations for problem 300 ~ 399 */

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
countBits(int num, int *returnSize)
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


/* 371. Sum of Two Integers */

/* Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.

Example:
 Given a = 1 and b = 2, return 3.
*/

int
getSum(int a, int b)
{
    while(b) {
        int carry = a & b;
        a = a ^ b;
        b = carry << 1;
    }

    // It seems that you can also cheat the OJ system with simple return a + b
    return a;
}

void
test_getSum()
{
    printf("%d\n", getSum(1, 2));
}


/* 389. Find the Difference */

/* Given two strings s and t which consist of only lowercase letters.

String t is generated by random shuffling string s and then add one more letter at a random position.

Find the letter that was added in t.

Example:
Input:
s = "abcd"
t = "abcde"

Output:
e

Explanation:
'e' is the letter that was added.

*/

char
findTheDifference(char *s, char *t)
{
    // TODO
    return 'a';
}

void
test_findTheDifference()
{

}
