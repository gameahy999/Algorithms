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

