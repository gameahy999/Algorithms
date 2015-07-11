#include <iostream>
#include "sort.h"
#include "util.h"
using namespace std;

int
main()
{
	int array[10] = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};

	Heap heap = Heap(array, 10);
	heap.heapsort();
	heap.print();

	return 0;
}
