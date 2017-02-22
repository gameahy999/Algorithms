#include <stdio.h>

#include "search.h"


int
slowSearch(int *nums, int numsSize, int target)
{
    if (nums == NULL) return -1;

    int index = 0;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == target) {
            index = i;
            break;
        }
    }
    return index;
}

// TODO: this array must be sorted before search.
int
binarySearch(int *nums, int numsSize, int target)
{
    return -1;
}
