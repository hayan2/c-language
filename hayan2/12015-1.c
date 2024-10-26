#define _CRT_SECURE_NO_WARNINGS
#define ARRAY_LEN 1000001
#include <stdio.h>

int A[ARRAY_LEN];
int LIS[ARRAY_LEN];

int main(void) {
	int N, idx = 0, low, high, mid;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}

	for (int i = 0; i < N; i++) {
		if (A[i] > LIS[idx]) {			
			LIS[++idx] = A[i];
		}
		else if (LIS[0] >= A[i]) {
			LIS[0] = A[i];
		}
		else {
			low = 0, high = idx;
			while (low <= high) {
				mid = (low + high) / 2;
				if (LIS[mid] < A[i]) {
					low = mid + 1;
				}
				else {
					high = mid - 1;
				}				
			}
			LIS[low] = A[i];
		}
	}

	printf("%d", idx);

	return 0;
}