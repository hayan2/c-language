#define _CRT_SECURE_NO_WARNINGS
#define ARRAY_LEN 10001
#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
	const int* A = a, * B = b;

	return (*A > *B) - (*A < *B);
}

// wrong - memory exceeded
int main(void) {
	int N, k;

	scanf("%d %d", &N, &k);
	
	int* B = (int*)malloc(sizeof(int) * (N * N));

	int idx = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			B[idx] = (i + 1) * (j + 1);
			idx++;
		}
	}

	qsort(B, N * N, sizeof(int), compare);

	printf("%d", B[k - 1]);

	return 0;
}