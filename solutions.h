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

/* 167. Two Sum II - Input array is sorted */
void test_twoSum_II();

/* 226. Invert Binary Tree */
void test_invertTree();

/* 283. Move Zeroes */
void test_moveZeros();

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

/* 442. Find All Duplicates in an Array */
void test_findDuplicates();

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

/* 492. Construct the Rectangle */
void test_constructRectangle();

/* 496. Next Greater Element I  */
void test_nextGreaterElement();

/* 500. Keyboard Row */
void test_findWords();

/* 506. Relative Ranks */
void test_findRelativeRanks();

/* 520. Detect Capital */
void test_detectCapitalUse();

/* 530. Minimum Absolute Difference in BST */
void test_getMinimumDifference();

#endif