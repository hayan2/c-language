#define _CRT_SECURE_NO_WARNINGS
#define ARRAY_LEN 100001
#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
	const int* A = a, * B = b;

	return (*A > *B) - (*A < *B);
}

int binarySearch(int* A, int N, int x);

int main(void) {
	int A[ARRAY_LEN], S[ARRAY_LEN];
	int N, M;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}

	scanf("%d", &M);

	for (int i = 0; i < M; i++) {
		scanf("%d", &S[i]);
	}

	qsort(A, N, sizeof(int), compare);

	for (int i = 0; i < M; i++) {
		printf("%d\n", binarySearch(A, N, S[i]));
	}

	return 0;
}

int binarySearch(int* A, int N, int x) {
	int low = 0, high = N - 1, mid;

	while (low <= high) {
		mid = (low + high) / 2;

		if (x > A[mid]) {
			low = mid + 1;
		}
		else if (x < A[mid]) {
			high = mid - 1;
		}
		else {
			return 1;
		}
	}

	return 0;
}