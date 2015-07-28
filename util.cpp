#include "util.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

int
gcd(int a, int b)
{
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a%b);
    }
}


/*
 *------------------------------------------------------------------------------
 *
 * RandomGenerator implementation
 *
 *   get int in [a, b] and get double in [a, b]
 *
 *------------------------------------------------------------------------------
 */

bool RandomGenerator::seedValid = false;

RandomGenerator::RandomGenerator()
{
    if (!seedValid) {
        srand(time(NULL));
        seedValid = true;
        printf("seed was set\n");
    }
}

RandomGenerator::~RandomGenerator()
{
}

int
RandomGenerator::getRandomInt(int a, int b)
{
    return a + rand() % (b-a+1);
}

double
RandomGenerator::getRandomDouble(double a, double b)
{
    return ((double)rand()/RAND_MAX)*(b-a) + a;
}

}
