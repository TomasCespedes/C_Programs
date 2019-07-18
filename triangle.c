// Author: Tomas Cespedes
// Purpose: check if an array contains a triangle
// Citations: 

#include <stdio.h> // This library defines printf and scanf
#include <stdbool.h> // This library defines the boolean data type


// Return whether an array of length n contains a triangle
bool triangle(int array[], int n) {
    
	// Start i at 0 and increment by one but stop at n-2 because
	// j will go all the way to the end.
	for (int i = 0; i <= n-2; i++) {
		// start j at i + 1 so j will never equal i.
		for (int j = i + 1; j <= n-1; j ++) {
			// start k at i because it has to check if 
			// i + j = i or i + j = j.
			for (int k = i; k <= n-1; k++) {
				// check if array values are equal to k
				if ( (array[i] + array[j]) == array[k] ) {
					return true;
				}
			}
		}
	}
	// no triangle so return false.
	return false;
	
}

// Interactive testing
void main() {
    
    int n;
    printf("Enter n: ");
    scanf("%d", &n);

    int array[n];
    printf("Enter array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }
    
    if (triangle(array, n)) {
        printf("Yes, this array contains a triangle.\n");
    } else {
        printf("No, this array does not contain a triangle.\n");
    }
}