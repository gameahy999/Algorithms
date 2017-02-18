#include <stdio.h>
#include <stdlib.h>

#include "util.h"

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
