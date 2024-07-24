#define _CRT_SECURE_NO_WARNINGS
#define ARRAY_LEN 501
#include <stdio.h>
#include <stdlib.h>

int map[ARRAY_LEN][ARRAY_LEN] = { 0, };
int cache[ARRAY_LEN][ARRAY_LEN] = { -1, };
int M, N;

int DFS(int x, int y);

int main(void) {
	scanf("%d %d", &M, &N);

	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	DFS(1, 1);

	return 0;
}

int DFS(int x, int y) {
	if (x == M && y == N) {
		return 1;
	}

	cache[x][y] = DFS(x + 1, y) + DFS(x, y + 1);



	return;
}