#define _CRT_SECURE_NO_WARNINGS
#define MIN(a, b) a > b ? b : a
#define ARRAY_LEN 501
#define INF 2147483646
#include <stdio.h>
#include <stdlib.h>

typedef struct Matrix {
	int row;
	int col;
}Matrix;

int main(void) {
	int dp[ARRAY_LEN][ARRAY_LEN] = { 0, };
	int N;

	scanf("%d", &N);

	Matrix* matrix = (Matrix*)malloc(sizeof(Matrix) * N);

	for (int i = 1; i <= N; i++) {
		scanf("%d %d", &matrix[i].row, &matrix[i].col);			
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N - i; j++) {
			dp[j][i + j] = INF;

			for (int k = j; k < i + j; k++) {
				dp[j][i + j] = MIN(dp[j][i + j], dp[j][k] + dp[k + 1][i + j] + (matrix[j].row * matrix[k + 1].row * matrix[i + j].col));
			}
		}
	}

	printf("%d", dp[1][N]);

	return 0;
}