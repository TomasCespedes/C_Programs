// Author: Tomas Cespedes
// Purpose: solve the robot attack problem
// Citations: 

#include <stdio.h>

// Print which minutes we should use the EMP.
void emp(int r[], int n, int m) {
	int arr[n + 1];
	arr[0] = 0;

	// Array for the minutes for after we're done
	int minutesarray[n];
	
	// Set all values equal to 0 to remove "junk"
	for (int j = 0; j <= n; j++) {
		minutesarray[j] = 0;
	}

	for (int i = 1; i <= n; i++) {
		arr[i] = 0;

		if (i == 1) {
		  arr[i] = r[i - 1];
		}
			
		// If current wave is greater than last wave 
		// mark the number of robots in that wave 
		else if (r[i - 1] > r[i-2] ){
		  if (i - m >= 0)
			arr[i] = r[i - 1] + arr[i - m];
		  else
			arr[i] = r[i - 1];
		} 

		else if (r[i - 1] == r[i - 2]) {
		  arr[i] = arr[i-1] + r[i - 1];
		}

		// If last wave is greater than current wave
		// mark the number of robots in that wave
		else if (r[i - 1] < r[i- 2]) {
		  arr[i] = arr[i - 1];
		}
			
		
		
	}

	// Go through the array backwards to figure out where
	// to fire the EMP
	for (int i = n; i > 0; i --){
		if (arr[i] == arr[i - 1]) {
			minutesarray[i] = i - 1;
			i = i - m;
		}
		else if (arr[i] > arr[i - 1]) {
			minutesarray[i] = i;
			i = i - m;
		}
		else if (arr[i] < arr[i - 1]) {
			minutesarray[i - 1] = i - 1;
			i = i - m;
		}
	}
  
	printf("%s", "You want to use the EMP at (minutes): ");
	for (int i = 0; i <= n ; i ++) {
		if (minutesarray[i] != 0) {
			printf("%d ", minutesarray[i]);
		}
	}
}

// Interactive test code
void main() {
    
    int n;
    printf("Number of waves (n): ");
    scanf("%d", &n);
    
    int r[n];
    printf("Wave sizes (r_1,...,r_n): ");
    for (int i = 0; i < n; i++)
        scanf("%d", &r[i]);
    
    int m;
    printf("Minutes for the EMP to recharge (m): ");
    scanf("%d", &m);
    
    printf("Best minutes at which to use the EMP:\n");
    emp(r, n, m);
}