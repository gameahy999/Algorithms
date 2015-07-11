#include <stdio.h>
#include "sort.h"
#include "util.h"

/* heap sort implementation */


Heap::Heap(int *array, int n)
{
	for (int i = 0; i < n; i++) {
		A[i] = array[i];
	}
	heap_size = n;

	build_max_heap();
}

Heap::~Heap()
{
}

void
Heap::max_heapify(int node)
{
	int l = left(node);
	int r = right(node);
	int largest = node;

	if (r < heap_size) {
		if (A[l] > A[node] || A[r] > A[node]) {
			if (A[l] >= A[r]) {
				largest = l;
			} else {
				largest = r;
			}
		}
	} else if (l < heap_size) {
		if (A[l] > A[node]) {
			largest = l;
		}
	}

	if (largest != node) {
		util::swap(A[node], A[largest]);
		max_heapify(largest);
	}
}

void
Heap::build_max_heap()
{
	for (int i = (heap_size-1)/2; i >= 0; i--) {
		max_heapify(i);
	}
}

void
Heap::heapsort()
{
	int len = heap_size;

	// build_max_heap();
	for (int i = len - 1; i >= 1; i--) {
		util::swap(A[0], A[i]);
		heap_size--;
		max_heapify(0);
	}

	heap_size = len;
}

void
Heap::print()
{
	for (int i = 0; i < heap_size; i++) {
		printf("%d  ", A[i]);
	}
	printf("\n");
}
