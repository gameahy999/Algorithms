#ifndef _SORT_H_
#define _SORT_H_


/*
 *------------------------------------------------------------------------------
 *
 * heap sort
 *
 * Sample code:
 *   int array[10] = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
 *   Heap heap = Heap(array, 10);
 *   heap.heapSort();
 *   heap.print();
 *
 *------------------------------------------------------------------------------
 */

#define MAX_SIZE 4096
class Heap
{
public:
    Heap(int *array, int n);
    ~Heap();

    void maxHeapify(int node);
    void heapSort();
    void print();

    // basic operation on index
    int parent(int index) {return (index-1)/2;}
    int left(int index) {return 2*index+1;}
    int right(int index) {return 2*index+2;}

private:
    void buildMaxHeap();
    int *A;
    int heapSize;
};


/*
 *------------------------------------------------------------------------------
 *
 * quick sort implementation
 *
 * Sample code:
 *   int array[10] = {4, 1, 3, 2, 16, 9, 9, 14, 8, 7};
 *   quickSort(array, 0, 9);
 *
 *------------------------------------------------------------------------------
 */

void quickSort(int *A, int p, int r);
void randomizedQuickSort(int *A, int p, int r);


/*
 *------------------------------------------------------------------------------
 *
 * counting sort implementation
 *
 * Sample code:
 *   int array[10] = {4, -1, 3, 2, 16, 9, 9, 14, 8, 7};
 *   int result[10];
 *   if (countingSort(array, result, 10, 20)) {
 *       util::printIntArray(result, 10);
 *   }
 *
 * Note:
 *   elements should be between 0 and k.
 *
 * Return:
 *   true if succeed, false if failed.
 *
 *------------------------------------------------------------------------------
 */

bool countingSort(int *A, int *B, int n, int k);


/*
 *------------------------------------------------------------------------------
 *
 * randomized select implementation
 *
 * Sample code:
 *   int array[10] = {4, 1, 3, 2, 16, 9, 9, 14, 8, 7};
 *   randomizedSelect(array, 0, 9, i);
 *
 * Return:
 *   the ist smallest element in the array from p to r.
 *
 *------------------------------------------------------------------------------
 */

int randomizedSelect(int *A, int p, int r, int i);

#endif
