#define _CRT_SECURE_NO_WARNINGS
#define MAX_LEN 51
#define DIR_LEN 4
#define VISITED 1
#define EXIST 1
#include <stdio.h>
#include <stdlib.h>

int	dx[DIR_LEN] = { -1, 0, 1, 0 };
int dy[DIR_LEN] = { 0, -1, 0, 1 };
int arr[MAX_LEN][MAX_LEN] = { 0, };
int visited[MAX_LEN][MAX_LEN] = { 0, };
int T, M, N, K, x, y;
int res = 0;

int sol(int x, int y) {
	if (visited[x][y] == VISITED) {
		return;
	}

	visited[x][y] = VISITED;

	for (int i = 0; i < DIR_LEN; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx > -1 && ny > -1 && nx < M && ny < N && arr[nx][ny] == EXIST) {
			sol(nx, ny);
		}
	}
}

int main(void) {
	scanf("%d", &T);

	while (T--) {
		scanf("%d %d %d", &M, &N, &K);

		for (int i = 0; i < K; i++) {
			scanf("%d %d", &x, &y);
			arr[x][y] = 1;
		}

		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				if (visited[i][j] != VISITED && arr[i][j] == EXIST) {
					res++;
					sol(i, j);
				}
			}
		}

		printf("%d\n", res);

		memset(arr, 0, sizeof(arr));
		memset(visited, 0, sizeof(visited));
		res = 0;
	}

	return 0;
}