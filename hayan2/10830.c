#define _CRT_SECURE_NO_WARNINGS
#define ARRAY_LEN 6
#define MOD 1000
#include <stdio.h>

typedef unsigned long long ull;

void sol(int res[][ARRAY_LEN], int A[][ARRAY_LEN], int N) {
	int tmp[ARRAY_LEN][ARRAY_LEN] = { 0, };

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				tmp[i][j] += (res[i][k] * A[k][j]) % MOD;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			res[i][j] = tmp[i][j] % MOD;
		}
	}
}

int main(void) {
	int A[ARRAY_LEN][ARRAY_LEN], res[ARRAY_LEN][ARRAY_LEN] = { 0, };
	ull B;
	int N;

	scanf("%d %lld", &N, &B);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &A[i][j]);
		}
		res[i][i] = 1;
	}

	while (B) {
		if (B & 1) {
			sol(res, A, N);
		}
		sol(A, A, N);

		B >>= 1;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%d ", res[i][j]);
		}
		printf("\n");
	}

	return 0;
}