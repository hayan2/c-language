#define _CRT_SECURE_NO_WARNINGS
#define ARRAY_LEN 16
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int N;
int board[ARRAY_LEN];
int result = 0;

int check(int row) {
	for (int col = 0; col < row; col++) {
		if (board[row] == board[col] || row - col == abs(board[row] - board[col])) {
			return 0;
		}
	}

	return 1;
}

void DFS(int row) {
	if (row == N) {
		result++;
		return;
	}

	for (int col = 0; col < N; col++) {
		board[row] = col;

		if (check(row)) {
			DFS(row + 1);
		}
	}
}

int main(void) {
	scanf("%d", &N);

	int row = 0;

	DFS(row);

	printf("%d", result);

	return 0;
}