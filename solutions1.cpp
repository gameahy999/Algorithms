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

/* Implementations for problem 100 ~ 199 */

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

struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

int
maxPoints(struct Point *points, int pointsSize)
{
    return 0;
}

void
test_maxPoints()
{

}


/* 167. Two Sum II - Input array is sorted */

/* Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution and you may not use the same element twice.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2
*/

/*
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *
twoSum_II(int *numbers, int numbersSize, int target, int *returnSize)
{
    *returnSize = 0;
    if (numbers == NULL) return NULL;

    int *ret = (int *)malloc(numbersSize * sizeof(int));
    memset(ret, 0, numbersSize * sizeof(int));

    int begin = 0;
    int end = numbersSize - 1;
    int index = 0;

    while (begin < end) {
        long currSum = numbers[begin] + numbers[end];

        if (currSum == target) {
            /* Note that your returned answers (both index1 and index2)
             *are not zero-based.
             */
            ret[index++] = begin + 1;
            ret[index++] = end + 1;

            begin++;
            end--;
        } else {
            if (currSum < target)
                begin++;
            else
                end--;
        }
    }
    *returnSize = index;

    return ret;
}

void
test_twoSum_II()
{
    int a[4] = {2, 7, 11, 15};
    int returnSize = 0;
    int *result = twoSum_II(a, 4, 9, &returnSize);
    util::printIntArray(result, returnSize);
    free(result);
}
