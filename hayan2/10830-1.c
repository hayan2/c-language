#define _CRT_SECURE_NO_WARNINGS
#define ARRAY_LEN 6
#define MOD 1000
#include <stdio.h>

int N;
typedef unsigned long long ull;

void sol(int res[][ARRAY_LEN], int A[][ARRAY_LEN]);

int main(void) {
	int A[ARRAY_LEN][ARRAY_LEN], res[ARRAY_LEN][ARRAY_LEN] = { 0, };
	ull B;

	scanf("%d %lld", &N, &B);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &A[i][j]);
		}
		res[i][i] = 1;
	}
	
	while (B) {
		printf("B : %d\n", B);
		if (B & 1) {
			sol(res, A);
		}
		sol(A, A);

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

void sol(int res[][ARRAY_LEN], int A[][ARRAY_LEN]) {
	printf("--------------------------------------------------\n");
	printf("BEFORE SOL\n");
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("\tres[%d][%d] : %d ", i, j, res[i][j]);
		}
		printf("\n");
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("\tA[%d][%d] : %d ", i, j, A[i][j]);
		}
		printf("\n");
	}
	

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

	printf("AFTER SOL\n");
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("\tres[%d][%d] : %d ", i, j, res[i][j]);
		}
		printf("\n");
	}

	printf("--------------------------------------------------\n");
}