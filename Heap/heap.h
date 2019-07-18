// Author: Tomas Cespedes
// Purpose: define a heap for integers
// Citations: 

#ifndef HEAP
#define HEAP

// Declare the heap data type
typedef struct {
	int next; // The next open index
	int n; // Length of the array
	int *array;
} Heap;

// Declare some associated functions
void setup_heap(Heap *heap, int n);
void insert_into_heap(Heap *heap, int value);
int extract_from_heap(Heap *heap);
void cleanup_heap(Heap *heap);

#endif
