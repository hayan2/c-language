#define _CRT_SECURE_NO_WARNINGS
#define ARRAY_SIZE 11
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int nCk(int N, int K) {
	static int arr[ARRAY_SIZE][ARRAY_SIZE];
	if (arr[N][K] > 0) {
		return arr[N][K];
	}
	else if (K == 0 || K == N) {
		return arr[N][K] = 1;
	}
	else if ((K < N) && (0 < K)) {
		return arr[N][K] = nCk(N - 1, K - 1) + nCk(N - 1, K);
	}
	else {
		return 0;
	}
}

int main(void) {
	int N, K;

	scanf("%d %d", &N, &K);

	printf("%d", nCk(N, K));

	return 0;
}