#define _CRT_SECURE_NO_WARNINGS
#define ARRAY_LEN 20000001
#define MOD 10000001
#include <stdio.h>
#include <stdlib.h>

int A[ARRAY_LEN] = { 0, }, S[ARRAY_LEN];

int main(void) {
	int N, M;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		int x;
		scanf("%d", &x);
		A[x + MOD]++;
	}

	scanf("%d", &M);

	for (int i = 0; i < M; i++) {
		scanf("%d", &S[i]);

		printf("%d ", A[S[i] + MOD]);
	}

	return 0;
}