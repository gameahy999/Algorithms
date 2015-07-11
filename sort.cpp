#include <stdio.h>
#include "sort.h"
#include "util.h"


/*
 *------------------------------------------------------------------------------
 *
 * heap sort implementation
 *
 * Sample code:
 *   int array[10] = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
 *   Heap heap = Heap(array, 10);
 *   heap.heapSort();
 *   heap.print();
 *
 *------------------------------------------------------------------------------
 */

Heap::Heap(int *array, int n)
{
	for (int i = 0; i < n; i++) {
		A[i] = array[i];
	}
	heapSize = n;

	buildMaxHeap();
}

Heap::~Heap()
{
}

void
Heap::maxHeapify(int node)
{
	int l = left(node);
	int r = right(node);
	int largest = node;

	if (r < heapSize) {
		if (A[l] > A[node] || A[r] > A[node]) {
			if (A[l] >= A[r]) {
				largest = l;
			} else {
				largest = r;
			}
		}
	} else if (l < heapSize) {
		if (A[l] > A[node]) {
			largest = l;
		}
	}

	if (largest != node) {
		util::swap(A[node], A[largest]);
		maxHeapify(largest);
	}
}

void
Heap::buildMaxHeap()
{
	for (int i = (heapSize-1)/2; i >= 0; i--) {
		maxHeapify(i);
	}
}

void
Heap::heapSort()
{
	int len = heapSize;

	for (int i = len - 1; i >= 1; i--) {
		util::swap(A[0], A[i]);
		heapSize--;
		maxHeapify(0);
	}

	heapSize = len;
}

void
Heap::print()
{
	for (int i = 0; i < heapSize; i++) {
		printf("%d  ", A[i]);
	}
	printf("\n");
}


/*
 *------------------------------------------------------------------------------
 *
 * quick sort implementation
 *
 * Sample code:
 *
 *
 *------------------------------------------------------------------------------
 */

static int
_partition(int *A, int p, int r)
{
	int pivot = A[r];
	int i = p-1;
	for (int j = p; j < r; j++) {
		if (A[j] <= pivot) {
			i++;
			util::swap(A[i], A[j]);
		}
	}

	util::swap(A[i+1], A[r]);
	return i+1;
}

void
quickSort(int *A, int p, int r)
{
	if (p < r) {
		int q = _partition(A, p, r);
		quickSort(A, p, q-1);
		quickSort(A, q+1, r);

		/* Merge : the array war sorted in place,
		 * so, need to do nothing for merge. */
	}
}


/*
 *------------------------------------------------------------------------------
 *
 * randomized quick sort implementation
 *
 * Sample code:
 *
 *
 *------------------------------------------------------------------------------
 */

static int
_randomizedPartition(int *A, int p, int r)
{
	// TODO:
	return 0;
}

void
randomizedQuickSort(int *A, int p, int r)
{
	if (p < r) {
		int q = _randomizedPartition(A, p, r);
		quickSort(A, p, q-1);
		quickSort(A, q+1, r);

		/* Merge : the array war sorted in place,
		 * so, need to do nothing for merge. */
	}
}
