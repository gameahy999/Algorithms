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

void printIntArray(int *A, int n);

}

#endif
