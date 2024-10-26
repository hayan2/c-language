#define _CRT_SECURE_NO_WARNINGS
#define ARRAY_LEN 1024
#include <stdio.h>

int A[ARRAY_LEN * ARRAY_LEN + 1];
int S[ARRAY_LEN * ARRAY_LEN + 1];

int main(void) {	
	int x1, y1, x2, y2;
	int N, M, res = 0, x = 0;

	scanf("%d %d", &N, &M);
	
	for (int i = 0; i < N * N; i++) {
		scanf("%d", &A[i]);
		if (i != 0 && i % N != 0) {
			S[i] = S[i - 1] + A[i];
		}
		else {
			S[i] = A[i];
		}
	}
	 
	for (int i = 0; i < M; i++) {
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		res = 0;
		for (int j = 0; j < (x2 - x1 + 1); j++) {
			if (y1 == 1) {
				res += S[(N * (x1 - 1)) + (N * j) + (y2 - 1)];
			}
			else {
				res += S[(N * (x1 - 1)) + (N * j) + (y2 - 1)] - S[(N * (x1 - 1)) + (N * j) + (y1 - 1) - 1];
			}
		}
		printf("%d\n", res);
	}

	/*
	for (int i = 0; i < N * N; i++) {
		if (i % N == 0) {
			printf("\n");
		}
		printf("%d ", A[i]);
	}
	printf("\n");
	for (int i = 0; i < N * N; i++) {
		if (i % N == 0) {
			printf("\n");
		}
		printf("%d ", S[i]);
	}
	*/

	return 0;
}