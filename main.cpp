#include <iostream>
#include <Windows.h>
#include "ruminations.h"
#include "sort.h"
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
    // Some practice on algorithms
    // util::WinTimer t = util::WinTimer();
    // t.start();

    // int array[10] = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
    // int result[10];

    // Heap heap = Heap(array, 10);
    // heap.heapSort();
    // heap.print();

    // cout << util::gcd(12, 24) << endl;

    // // quickSort(array, 0, 9);
    // // util::printIntArray(array, 10);

    // if (countingSort(array, result, 10, 20)) {
    //     util::printIntArray(result, 10);
    // }

    // t.stop();
    // t.printResult("counting sort");

    // double min = 15;
    // double max = 15;
    //     util::RandomGenerator r = util::RandomGenerator();

    // for (int i = 0; i < 1000000; i++) {
    //     // cout << util::getRandomInt(10, 20) << endl;
    //     double ret = r.getRandomDouble(10, 20);
    //     if (ret > max) max = ret;
    //     if (ret < min) min = ret;
    // }

    // cout << "max == " << max << endl;
    // cout << "min == " << min << endl;
    // for (int i = 1; i <= 10; i++) {
    //     cout << randomizedSelect(array, 0, 9, i) << endl;
    // }

    // Some practice on Ruminations on C++
    // Test *t = new Test;
    // delete t;
    // Test t = Test();
    // Test s;
    // Test t(s);
    // s = t;



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
