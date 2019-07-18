// Author: Tomas Cespedes
// Purpose: implement a heap for integers
// Citations: 

#include <stdlib.h>
#include "heap.h"

// How to initialize a heap
void setup_heap(Heap *heap, int n) {
	heap->next = 1;
	heap->n = n+1;
	heap->array = malloc(heap->n * sizeof(int));
}

// Swap the values pointed at by p and q
void swap(int *p, int *q) {
	int temp = *p;
	*p = *q;
	*q = temp;
}

// How to insert a value into a heap
void insert_into_heap(Heap *heap, int value) {
	
	// Put the item in the first open spot
	heap->array[heap->next] = value;
	heap->next++;
	
	// Here's where it is now
	int index = heap->next - 1;
	int parentIndex = index / 2;

	// Bubble it up until its parent is smaller	
	while (index > 1 && heap->array[index] < heap->array[parentIndex]) {
		swap(&heap->array[index], &heap->array[parentIndex]);
		index = parentIndex;
		parentIndex = index / 2;
	}
}

// Find the index of the smaller child 
int smallerChildIndex(Heap *heap, int parentIndex) {

	int leftChildIndex = 2 * parentIndex;
	int rightChildIndex = leftChildIndex + 1;

	// No children
	if (leftChildIndex >= heap->next) {
		return parentIndex;
	}

	// One child
	if (rightChildIndex >= heap->next) {
		return leftChildIndex;
	}

	// Two children
	int leftChild = heap->array[leftChildIndex];
	int rightChild = heap->array[rightChildIndex];
	return leftChild < rightChild ? leftChildIndex : rightChildIndex;
}

// How to extract the minimum value from a heap
int extract_from_heap(Heap *heap) {

	// Grab the root out
	int min = heap->array[1];
	heap->next--;

	// Replace it with the last item
	heap->array[1] = heap->array[heap->next];
	int index = 1;

	// Bubble that item down until both its children are larger
	int childIndex = smallerChildIndex(heap, index);
	while (heap->array[childIndex] < heap->array[index]) {
		swap(&heap->array[index], &heap->array[childIndex]);
		index = childIndex;
		childIndex = smallerChildIndex(heap, index);
	}
	
	// Return the old root
	return min;
}

// How to release the memory used by a heap
void cleanup_heap(Heap *heap) {
	free(heap->array);
}
