#define _CRT_SECURE_NO_WARNINGS
#define MAX(a, b) a > b ? a : b
#define ARRAY_LEN 101
#define POLE 2
#define LEFT 0
#define RIGHT 1
#include <stdio.h>
#include <stdlib.h>

int compare(const void* pa, const void* pb) {
	const int* a = *(const int**)pa;
	const int* b = *(const int**)pb;

	if (a[0] == b[0]) {
		return a[1] - b[1];
	}
	else {
		return a[0] - b[0];
	}
}

int main(void) {
	int** arr;
	int dp[ARRAY_LEN];
	int N, result = 0;

	scanf("%d", &N);

	arr = malloc(N * sizeof(int*));

	for (int i = 0; i < N; dp[i++] = 0) {
		arr[i] = malloc(POLE * sizeof(int));
		scanf("%d %d", &arr[i][LEFT], &arr[i][RIGHT]);
	}

	qsort(arr, N, sizeof arr[rand() % (ARRAY_LEN - 1)], compare);

	for (int i = 0; i < N; i++) {	
		for (int j = i - 1; j >= 0; j--) {			
			if (arr[i][LEFT] > arr[j][LEFT] && arr[i][RIGHT] < arr[j][RIGHT]) {
				/*
				printf("arr[%d][LEFT] : %2d  arr[%d][RIGHT] : %2d\n", i, arr[i][LEFT], i, arr[i][RIGHT]);
				printf("arr[%d][LEFT] : %2d  arr[%d][RIGHT] : %2d\n", j, arr[j][LEFT], j, arr[j][RIGHT]);
				printf("i : %d j : %d\n", i, j);
				*/
				dp[i] = MAX(dp[i] + 1, dp[j] + 1);
				/*
				printf("dp[%d] : %d\n", i, dp[i]);
				*/
				result = MAX(result, dp[i]);
			}
		}
	}

	printf("%d", result);

	return 0;
}