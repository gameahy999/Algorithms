#include <stdio.h>
#include <string.h>
#include "misc.h"

static int
getSize(int data[])
{
    return sizeof(data);
}

void
test_sizeof()
{
    int data1[] = {1, 2, 3, 4, 5};
    int size1 = sizeof(data1);

    int *data2 = data1;
    int size2 = sizeof(data2);

    int size3 = getSize(data1);

    printf("%d, %d, %d\n", size1, size2, size3);
}

static void
toUpper(char *str)
{
    int len = strlen(str);
    for (int i = 0; i < len; ++i) {
        str[i] &= 0xDF;
    }
}

static void
toLower(char *str)
{
    int len = strlen(str);
    for (int i = 0; i < len; ++i) {
        str[i] |= 0x20;
    }
}

void
test_chars()
{
    char a[] = "Hello";
    char b[] = "WOrLD";
    toUpper(a);
    toLower(b);
    printf("to upper: %s\n", a);
    printf("to lower: %s\n", b);
}
