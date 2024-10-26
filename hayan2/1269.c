#define _CRT_SECURE_NO_WARNINGS
#define ARRAY_SIZE 200001
#include <stdio.h>
#include <stdlib.h>

int A[ARRAY_SIZE];
int B[ARRAY_SIZE];

int compare(const void* a, const void* b);
int binary_search(int N, int key);

int main(void) {
	int N, M;

	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}

	for (int i = 0; i < M; i++) {
		scanf("%d", &B[i]);
	}

	qsort(A, N, sizeof(int), compare);

	int res = 0;

	for (int i = 0; i < M; i++) {
		res += binary_search(N, B[i]);
	}

	printf("%d", N + M - (res * 2));

	return 0;
}

int compare(const void* a, const void* b) {
	return *((int*)a) - *((int*)b);
}

int binary_search(int N, int key) {
	int low = 0, high = N - 1;

	while (low <= high) {
		int mid = (low + high) / 2;
		if (A[mid] == key) {
			return 1;
		}
		else if (A[mid] < key) {
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}

	return 0;
}