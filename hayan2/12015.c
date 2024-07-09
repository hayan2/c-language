#define _CRT_SECURE_NO_WARNINGS
#define ARRAY_LEN 1000001
#include <stdio.h>

int A[ARRAY_LEN];
int LIS[ARRAY_LEN];

int binarySearch(int N);

// wrong
int main(void) {
	int N;
		
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}

	printf("%d\n", binarySearch(N));	

	return 0;
}

int binarySearch(int N) {
	int low = 0, high = 0, idx = 0, mid = 0;
	LIS[idx] = A[0];

	for (int i = 1; i < N; i++) {		
		
		/*
		for (int i = 0; i <= idx; i++) {
			printf("%d ", LIS[i]);
		}
		printf("\n");
		*/
		
		
		low = 0, high = idx;
		if (A[i] > LIS[idx]) {
			idx++;
			LIS[idx] = A[i];
			continue;
		}

		if (A[i] == LIS[idx]) {
			continue;
		}

		while (low <= high) {
			mid = (low + high) / 2;
			
			if (LIS[low] == A[i] || LIS[high] == A[i]) {
				break;
			}
			if (LIS[mid] > A[i]) {
				high = mid - 1;				
			}
			else {			
				if (LIS[mid] == A[i]) {
					break;
				}
				low = mid + 1;
			}
		}
		if (LIS[mid] == A[i]) {
			continue;
		}
		LIS[low] = A[i];
	}
			
	/*
	for (int i = 0; i <= idx; i++) {
		printf("%d ", LIS[i]);
	}
	printf("\n");
	*/	
	
	return idx + 1;
}