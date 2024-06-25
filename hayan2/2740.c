#define _CRT_SECURE_NO_WARNINGS
#define ARRAY_LEN 101
#include <stdio.h>

int A[ARRAY_LEN][ARRAY_LEN] = { 0, };
int B[ARRAY_LEN][ARRAY_LEN] = { 0, };
int res[ARRAY_LEN][ARRAY_LEN] = { 0, };

void multiplicationOfMatricies(int x, int y, int M);

int main(void) {
	int N, M, K;

	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &A[i][j]);
		}
	}

	scanf("%d %d", &M, &K);
	
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < K; j++) {
			scanf("%d", &B[i][j]);
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < K; j++) {
			multiplicationOfMatricies(i, j, M);
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < K; j++) {
			printf("%d ", res[i][j]);
		}
		printf("\n");
	}

	return 0;
}

void multiplicationOfMatricies(int x, int y, int M) {
	for (int i = 0; i < M; i++) {
		res[x][y] += A[x][i] * B[i][y];
	}
}