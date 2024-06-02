#define _CRT_SECURE_NO_WARNINGS
#define ARRAY_LEN 101
#define POLE 501
#define POS 2
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
	int arr[ARRAY_LEN][POS];
	int dp[POLE];
	int N;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d %d", &arr[i][LEFT], &arr[i][RIGHT]);
	}

	qsort(arr, N, sizeof(int), compare);

	for (int i = 0; i < N; i++) {
		printf("%d %d\n", arr[i][LEFT], arr[i][RIGHT]);
	}

	return 0;
}