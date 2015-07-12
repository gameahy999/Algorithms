#include "util.h"

#include <stdio.h>

namespace util
{

void
swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int
max(int a, int b)
{
    return a > b ? a : b;
}

int
min(int a, int b)
{
    return a < b ? a : b;
}

int
max(int a, int b, int c)
{
    int temp = max(a, b);
    return max(c, temp);
}

int
min(int a, int b, int c)
{
    int temp = min(a, b);
    return min(c, temp);
}

int
max(int *A, int n)
{
    int result = A[0];

    for (int i = 1; i < n; i++) {
        if (A[i] > result) {
            result = A[i];
        }
    }

    return result;
}

int
min(int *A, int n)
{
    int result = A[0];

    for (int i = 1; i < n; i++) {
        if (A[i] < result) {
            result = A[i];
        }
    }

    return result;
}

void
printIntArray(int *A, int n)
{
    for (int i = 0; i < n; i++) {
        printf("%d  ", A[i]);
    }
    printf("\n");
}

}
