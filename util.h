#ifndef _UTIL_H_
#define _UTIL_H_

/*
 *------------------------------------------------------------------------------
 *
 * Implementations of utils in common use
 *
 * Sample code:
 * util::swap(a, b);
 * util::...
 *
 *------------------------------------------------------------------------------
 */

namespace util
{

void swap(int &a, int &b);

int max(int a, int b);
int max(int a, int b, int c);
int max(int *A, int n);
int min(int a, int b);
int min(int a, int b, int c);
int min(int *A, int n);

void printIntArray(int *A, int n);

int gcd(int a, int b);

class RandomGenerator
{
public:
    RandomGenerator();
    ~RandomGenerator();
    int getRandomInt(int a, int b);
    double getRandomDouble(double a, double b);

private:
    static bool seedValid;
};

}

#endif
