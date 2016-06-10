#include <stdio.h>
#include "twoSum.h"
#include "sort.h"

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