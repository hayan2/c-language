#define _CRT_SECURE_NO_WARNINGS
#define ARRAY_LEN 500001
#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
	const int* A = a, * B = b;

	return (*A > *B) - (*A < *B);
}

int lowerBound(int* A, int key, int N);
int upperBound(int* A, int key, int N);
void sol(int* A, int* S, int N, int M);

int A[ARRAY_LEN], S[ARRAY_LEN];

int main(void) {
	int N, M;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}

	qsort(A, N, sizeof(int), compare);

	scanf("%d", &M);

	for (int i = 0; i < M; i++) {
		scanf("%d", &S[i]);
	}

	sol(A, S, N, M);

	return 0;
}

void sol(int* A, int* S, int N, int M) {	
	int lower, upper;

	for (int i = 0; i < M; i++) {
		lower = lowerBound(A, S[i], N);
		upper = upperBound(A, S[i], N);

		printf("%d ", upper - lower);
	}	
}

int lowerBound(int* A, int key, int N) {
	int low = 0, high = N - 1, mid;
	
	while (low < high) {
		mid = (low + high) / 2;

		if (A[mid] >= key) {
			high = mid;
		}
		else {
			low = mid + 1;
		}
	}

	return high;
}

int upperBound(int* A, int key, int N) {
	int low = 0, high = N - 1, mid;

	while (low < high) {
		mid = (low + high) / 2;

		if (A[mid] > key) {
			high = mid;
		}
		else {
			low = mid + 1;
		}
	}

	if (A[high] == key) {
		return high + 1;
	}

	return high;
}