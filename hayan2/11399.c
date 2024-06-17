#define _CRT_SECURE_NO_WARNINGS
#define ARRAY_LEN 1001
#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
	const int* A = a, * B = b;

	return (*A > *B) - (*A < *B);
}


int main(void) {
	int arr[ARRAY_LEN] = { 0, };
	int S[ARRAY_LEN] = { 0, };
	int N, res = 0;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);		
	}

	qsort(arr, N, sizeof arr[0], compare);

	S[0] = arr[0];
	res = S[0];
	for (int i = 1; i < N; i++) {
		S[i] = S[i - 1] + arr[i];
		res += S[i];
	}

	printf("%d", res);

	return 0;
}