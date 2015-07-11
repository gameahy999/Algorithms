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
max(int a, int b, int c)
{
	int temp = max(a, b);
	return max(c, temp);
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
