#define _CRT_SECURE_NO_WARNINGS
#define ARRAY_LEN 501
#define DIR 4
#include <stdio.h>
#include <stdlib.h>

int map[ARRAY_LEN][ARRAY_LEN] = { 0, };
int cache[ARRAY_LEN][ARRAY_LEN];
int M, N;

typedef struct Direction {
	int x;
	int y;
}Direction;

int DFS(int x, int y, Direction* dir);
void initDir(Direction* dir);

int main(void) {
	Direction* dir = (Direction*)malloc(sizeof(Direction) * DIR);
	initDir(dir);

	memset(cache, -1, sizeof(cache));

	scanf("%d %d", &M, &N);

	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	printf("%d", DFS(1, 1, dir));

	return 0;
}

int DFS(int x, int y, Direction* dir) {
	if (x == M && y == N) {
		return 1;
	}

	if (cache[x][y] == -1) {
		cache[x][y] = 0;

		for (int i = 0; i < DIR; i++) {
			int nx = x + dir[i].x;
			int ny = y + dir[i].y;

			if (map[nx][ny] != 0 && map[x][y] > map[nx][ny]) {
				cache[x][y] += DFS(nx, ny, dir);
			}
		}
	}

	return cache[x][y];
}

void initDir(Direction* dir) {
	dir[0].x = -1;
	dir[0].y = 0;

	dir[1].x = 1;
	dir[1].y = 0;

	dir[2].x = 0;
	dir[2].y = -1;

	dir[3].x = 0;
	dir[3].y = 1;
}