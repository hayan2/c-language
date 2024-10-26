#define _CRT_SECURE_NO_WARNINGS
#define MAX_LEN 1001
#define DIR 4
#define RIPE 1
#define VISITED 1
#define UNRIPE 0
#define EMPTY -1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Coordinate {
	int x;
	int y;
}Coordinate;

int cache[MAX_LEN][MAX_LEN] = { 0, };
int M, N, lim, cnt, front = 0, rear = 0;

void initDir(Coordinate* dir) {
	dir[0].x = -1;
	dir[0].y = 0;

	dir[1].x = 0;
	dir[1].y = -1;

	dir[2].x = 1;
	dir[2].y = 0;
	
	dir[3].x = 0;
	dir[3].y = 1;
}

int sol(Coordinate* queue, Coordinate* dir) {
	int res = 0;
	int checkDate = rear;

	while (front < rear) {
		int dx = queue[front].x;
		int dy = queue[front].y;
		front++;

		if (front > checkDate) {
			checkDate = rear;
			res++;
		}

		for (int i = 0; i < DIR; i++) {
			int nx = dx + dir[i].x;
			int ny = dy + dir[i].y;

			if (nx < 0 || ny < 0 || nx >= N || ny >= M) {
				continue;
			}

			if (cache[nx][ny] == UNRIPE) {
				cache[nx][ny] = RIPE;
				queue[rear].x = nx;
				queue[rear].y = ny;
				rear++;
				cnt++;
			}
		}
	}

	if (cnt != lim) {
		return -1;
	}

	return res;
}

int main(void) {
	scanf("%d %d", &M, &N);

	lim = M * N;

	Coordinate* queue = (Coordinate*)malloc(sizeof(Coordinate) * lim);
	Coordinate* dir = (Coordinate*)malloc(sizeof(Coordinate) * DIR);

	initDir(dir);
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &cache[i][j]);

			if (cache[i][j] == EMPTY) {
				lim--;
			}
			if (cache[i][j] == RIPE) {
				queue[rear].x = i;
				queue[rear].y = j;

				cnt++;
				rear++;
			}
		}
	}

	printf("%d", sol(queue, dir));

	return 0;
}