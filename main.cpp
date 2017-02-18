#include <iostream>
#include <Windows.h>

#include "assignmentOperator.h"
#include "linkedList.h"
#include "myException.h"
#include "ruminations.h"
#include "sort.h"
#include "solutions.h"
#include "twoSum.h"
#include "util.h"
#include "winTimer.h"

using namespace std;

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
    // test_linkedList();
    // test_assignmentOperator();
    // try {
    //     test_exception();
    // } catch (MyException &e) {
    //     cout << e.what() << endl;
    // }
    // test_countBits();
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
