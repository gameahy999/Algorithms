#ifndef _SOLUTIONS_H_
#define _SOLUTIONS_H_


/* 33. Search in Rotated Sorted Array */
void test_search();

/* 69. Sqrt(x) */
void test_mySqrt();

/* 89. Gray Code */
void test_grayCode();

/* 149. Max Points on a Line */
struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};
void test_maxPoints();

/* 226. Invert Binary Tree */
void test_invertTree();

/* 338. Counting Bits */
void test_countBits();

/* 496. Next Greater Element I  */
void test_nextGreaterElement();

#endif