#include <iostream>
#include "sort.h"
#include "util.h"
#include "winTimer.h"
#include <Windows.h>
using namespace std;

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

    // util::WinTimer t = util::WinTimer();
    // t.start();

    int array[10] = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
    // int result[10];

    // // Heap heap = Heap(array, 10);
    // // heap.heapSort();
    // // heap.print();

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
    for (int i = 1; i <= 10; i++) {
        cout << randomizedSelect(array, 0, 9, i) << endl;
    }

    return 0;
}
