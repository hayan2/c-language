#define _CRT_SECURE_NO_WARNINGS
#define MAX(a, b) a > b ? a : b
#define ARRAY_LEN 1001
#include <stdio.h>

int main(void) {
	int arr[ARRAY_LEN];
	int dpLeft[ARRAY_LEN], dpRight[ARRAY_LEN];
	int N, result = 0;

	scanf("%d", &N);

	for (int i = 0; i < N; dpLeft[i++] = 1);
	for (int i = 0; i < N; dpRight[i++] = 1);

	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	for (int i = 0; i < N; i++) {
		for (int j = i - 1; j >= 0; j--) {
			if (arr[i] > arr[j] && dpLeft[i] <= dpLeft[j]) {
				dpLeft[i] = dpLeft[j] + 1;
			}
		}		
	}

	for (int i = N - 1; i >= 0; i--) {
		for (int j = i + 1; j < N; j++) {
			if (arr[i] > arr[j] && dpRight[i] <= dpRight[j]) {
				dpRight[i] = dpRight[j] + 1;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		result = MAX(result, dpLeft[i] + dpRight[i]);
	}

	printf("%d", result - 1);

	return 0;
}