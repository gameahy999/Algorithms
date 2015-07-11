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

    util::WinTimer t = util::WinTimer();
    t.start();

    int array[10] = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};

    // Heap heap = Heap(array, 10);
    // heap.heapSort();
    // heap.print();
    quickSort(array, 0, 9);
    util::printIntArray(array, 10);

    t.stop();
    t.printResult();
    t.printResult("quick sort");


    return 0;
}
