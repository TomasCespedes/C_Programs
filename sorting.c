// Author: Tomas Cespedes
// Purpose: simple sorting algorithms
// Citations: 

#include <stdio.h>

// Swap the values pointed at by p and q
void swap(int *p, int*q) {
	int temp = *p;
	*p = *q;
	*q = temp;
	
}


// Sort an array of length n using O(n^2) insertion sort
void insertion_sort(int array[], int n) {
	
	for (int i = 1; i < n; i++) {
		int j = i;
		
		while (j > 0 && array[j] < array[j-1]) {
			swap(&array[j], &array[j-1]);
			j--;
		}
	}
}

// Sort an array of length n using O(n^2) selection sort
void selection_sort(int array[], int n) {
	
	for (int i = 0; i < n-1; i++) {
		
		int j = i;
		for (int k = j+1; k < n; k++) {
			if (array[k] < array[j]) {
				j = k;
			}
		}
		
		swap(&array[i], &array[j]);
	}
}

// Interactive testing
void main() {
	
	int n;
	printf("Enter n: ");
	scanf("%d", &n);
	
	int A[n];
	int B[n];
	printf("Enter array: ");
	for (int i = 0; i < n; i++) {
		scanf("%d", &A[i]);
		B[i] = A[i];
	}
	
	insertion_sort(A, n);
	selection_sort(B, n);
	
	printf("IS\tSS\n");
	for (int i = 0; i < n; i++) {
		printf("%d\t%d\n", A[i], B[i]);
	}
}
