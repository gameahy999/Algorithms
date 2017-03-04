#ifndef _SOLUTIONS_H_
#define _SOLUTIONS_H_

/* 1. Two Sum */
void test_twoSum();

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

/* 292. Nim Game */
void test_canWinNim();

/* 338. Counting Bits */
void test_countBits();

/* 344. Reverse String */
void test_reverseString();

/* 371. Sum of Two Integers */
void test_getSum();

/* 389. Find the Difference */
void test_findTheDifference();

/* 412. Fizz Buzz */
void test_fizzBuzz();

/* 438. Find All Anagrams in a String */
void test_findAnagrams();

/* 448. Find All Numbers Disappeared in an Array */
void test_findDisappearedNumbers();

/* 461. Hamming Distance */
void test_hammingDistance();

/* 463. Island Perimeter */
void test_islandPerimeter();

/* 476. Number Complement */
void test_findComplement();

/* 485. Max Consecutive Ones */
void test_findMaxConsecutiveOnes();

/* 496. Next Greater Element I  */
void test_nextGreaterElement();

/* 500. Keyboard Row */
void test_findWords();

/* 520. Detect Capital */
void test_detectCapitalUse();

#endif