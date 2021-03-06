#include "solutions.h"
#include "misc.h"
#include "linkedList.h"

/*
 *------------------------------------------------------------------------------
 *
 * Functions running before/after main function.
 *
 * It's a feature of gcc compiler, shouldn't depend on it excessively.
 * The number is priority, 0 ~ 100 is reserved.
 * Smaller, higher priority.
 *
 *------------------------------------------------------------------------------
 */

// static void constructBeforeMain(void) __attribute__ ((constructor(150)));
// static void deconstructAfterMain(void) __attribute__ ((destructor(150)));


/*
 *------------------------------------------------------------------------------
 *
 * Entry point of the whole program.
 *
 * It's only a place to have a test.
 *
 *------------------------------------------------------------------------------
 */

int
main(int argc, char **argv)
{
    // test_twoSum();
    // test_addTwoNumbers();
    test_isPalindrome();
    // test_linkedList();
    // test_assignmentOperator();
    // try {
    //     test_exception();
    // } catch (MyException &e) {
    //     cout << e.what() << endl;
    // }
    // test_countBits();
    // test_grayCode();
    // test_nextGreaterElement();
    // test_findAnagrams();
    // test_hammingDistance();
    // test_findComplement();
    // test_findWords();
    // test_reverseString();
    // test_fizzBuzz();
    // test_islandPerimeter();
    // test_findMaxConsecutiveOnes();
    // test_canWinNim();
    // test_twoSum_II();
    // test_moveZeros();
    // test_getSum();
    // test_findTheDifference();
    // test_detectCapitalUse();
    // test_findDisappearedNumbers();
    // test_constructRectangle();
    // test_getMinimumDifference();
    // test_findDuplicates();
    // test_findPoisonedDuration();
    // test_sumOfLeftLeaves();
    // test_findRelativeRanks();
    // test_sizeof();
    // test_chars();
    return 0;
}

// static void
// constructBeforeMain(void)
// {
//     printf("--------------Begin-------------\n");
// }

// static void
// deconstructAfterMain(void)
// {
//     printf("---------------End--------------\n");
// }
