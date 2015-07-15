#include <stdio.h>
#include "sort.h"
#include "util.h"


/*
 *------------------------------------------------------------------------------
 *
 * heap sort implementation
 *
 *------------------------------------------------------------------------------
 */

Heap::Heap(int *array, int n)
{
    A = array;
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
 *------------------------------------------------------------------------------
 */

static int
_randomizedPartition(int *A, int p, int r)
{
    util::RandomGenerator rg = util::RandomGenerator();
    int randomIndex = rg.getRandomInt(p, r);
    util::swap(A[r], A[randomIndex]);
    return _partition(A, p, r);
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


/*
 *------------------------------------------------------------------------------
 *
 * counting sort implementation
 *
 *------------------------------------------------------------------------------
 */

bool
countingSort(int *A, int *B, int n, int k)
{
    if (k < n ||
        k < util::max(A, n) ||
        util::min(A, n) < 0) {
        printf("Hypothesis of counting sort is not established\n");
        return false;
    }

    int *C = new int[k];

    // Initialized the temp memory.
    for (int i = 0; i < k; i++) {
        C[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        C[A[i]]++;
    }

    for (int i = 1; i < k; i++) {
        C[i] = C[i] + C[i-1];
    }

    for (int j = n-1; j >= 0; j--) {
        B[C[A[j]] - 1] = A[j];
        C[A[j]]--;
    }

    delete [] C;
    return true;
}

/*
 *------------------------------------------------------------------------------
 *
 * randomized select implementation
 *
 *------------------------------------------------------------------------------
 */

int
randomizedSelect(int *A, int p, int r, int i)
{
    if (p == r) {
        return A[p];
    }

    int pivot = _randomizedPartition(A, p, r);
    int k = pivot-p+1;
    if (i == k) {
        return A[pivot];
    } else if (i < k) {
        return randomizedSelect(A, p, pivot-1, i);
    } else {
        return randomizedSelect(A, pivot+1, r, i-k);
    }
}
