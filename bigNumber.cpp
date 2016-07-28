#include <stdio.h>
#include <string.h>
#include "bigNumber.h"


void
printNumber(char *number, int len)
{

}

bool
increment(char *number, int len)
{
    return false;
}

void
print1ToMaxOfNDigits(int n)
{
    if (n <= 0) return;

    char *number = new char[n + 1];
    memset(number, '0', n);
    number[n] = '\0';

    while (!increment(number, n)) {
        printNumber(number, n);
    }

    delete [] number;
}

void
test_bigNumber()
{

}
