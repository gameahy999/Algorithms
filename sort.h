#ifndef _SORT_H_
#define _SORT_H_


/* definition of Heap */
#define MAX_SIZE 4096
class Heap
{
public:
	Heap(int *array, int n);
	~Heap();

	void max_heapify(int node);
	void heapsort();
	void print();

	// basic operation on index
	int parent(int index) {return (index-1)/2;}
	int left(int index) {return 2*index+1;}
	int right(int index) {return 2*index+2;}

private:
	void build_max_heap();
	int A[MAX_SIZE];
	int heap_size;
};


#endif
