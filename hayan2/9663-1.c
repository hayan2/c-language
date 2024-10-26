#define _CRT_SECURE_NO_WARNINGS
#define ARRAY_LEN 16
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int N;
int result = 0;
int board[ARRAY_LEN];

int check(int x) {
	for (int i = 0; i < x; i++) {
		if (board[x] == board[i] || x - i == abs(board[x] - board[i])) {
			return 0;
		}
	}
	
	return 1;
}

void DFS(int x) {
	if (x == N) {
		result++;
		return;
	}

	for (int i = 0; i < N; i++) {
		board[x] = i;
		if (check(x)) {
			DFS(x + 1);
		}
	}
}

int main(void) {
	scanf("%d", &N);

	DFS(0);

	printf("%d", result);

	return 0;
}