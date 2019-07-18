// Author: Tomas Cespedes
// Purpose: do a heapsort
// Citations: 

#include <stdio.h>
#include "heap.h"

void main() {

	int n = 8;
	int array[] = {7, 2, 5, 8, 6, 1, 4, 3};

	Heap heap;
	setup_heap(&heap, n);

	for (int i = 0; i < n; i++) {
		insert_into_heap(&heap, array[i]);
	}

	for (int i = 0; i < n; i++) {
		array[i] = extract_from_heap(&heap);
	}

	for (int i = 0; i < n; i++) {
		printf("%d ", array[i]);
	} printf("\n");
}