#define _CRT_SECURE_NO_WARNINGS
#define MAX(a, b) a > b ? a : b
#define ARRAY_LEN 100001
#define MINIMUM_NUM -10000001
#include <stdio.h>

int main(void) {
	int A[ARRAY_LEN];
	int S[ARRAY_LEN] = { 0, };
	int N, K, res = MINIMUM_NUM;

	scanf("%d %d", &N, &K);

	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
		if (i == 0) {
			S[i] = A[i];
		}
		if (i < K && i != 0) {
			S[i] = S[i - 1] + A[i];
		}
	}

	for (int i = K; i < N; i++) {
		S[i] = S[i - 1] + A[i] - A[i - K];
	}

	for (int i = K - 1; i < N; i++) {
		res = MAX(res, S[i]);
	}

	printf("%d", res);

	return 0;
}