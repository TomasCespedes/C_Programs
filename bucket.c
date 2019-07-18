// Author: Tomas Cespedes
// Purpose: bucket sorting
// Citations: https://www.thecrazyprogrammer.com/2017/02/bucket-sort-in-c.html
// Citations: http://scanftree.com/programs/c/c-program-to-implement-bucket-sort/

#include <stdio.h>

// Sort an array of length n whose values are all chosen randomly from {1,2,...,k}
void bucket_sort(int array[], int n, int k) {
    int i, j;  
	int countarray[k + 1];

	// Initialize 0 into the array
    for (i = 0; i < k + 1; i++) {
        countarray[i] = 0;
	}
		
	
    for (i = 0; i < n; i++) {
        (countarray[array[i]])++;
	}
		
    for (i = 0, j = 0; i < k + 1; i++) {
        for(; countarray[i] > 0; (countarray[i])--) {
            array[j] = i;
			j++; 
		}
	}
}

// Interactive testing
void main() {
    
    int n;
    printf("Enter n: ");
    scanf("%d", &n);

    int k;
    printf("Enter k: ");
    scanf("%d", &k);
    
    int array[n];
    printf("Enter array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }
    
    bucket_sort(array, n, k);
    
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}
