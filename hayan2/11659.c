#define _CRT_SECURE_NO_WARNINGS
#define ARRAY_LEN 100001
#include <stdio.h>

// prefix sum
int main(void) {
	int arr[ARRAY_LEN] = { 0, };
	int S[ARRAY_LEN] = { 0, };
	int N, M, l, r;

	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++) {
		scanf("%d", &arr[i]);
		S[i] = arr[i] + S[i - 1];
	}

	for (int i = 0; i < M; i++) {
		scanf("%d %d", &l, &r);
		printf("%d\n", S[r] - S[l - 1]);
	}

	return 0;
}