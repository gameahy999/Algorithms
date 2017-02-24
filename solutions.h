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

/* 438. Find All Anagrams in a String */
void test_findAnagrams();

/* 461. Hamming Distance */
void test_hammingDistance();

/* 476. Number Complement */
void test_findComplement();

/* 496. Next Greater Element I  */
void test_nextGreaterElement();

/* 500. Keyboard Row */
void test_findWords();

#endif