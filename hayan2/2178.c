#define _CRT_SECURE_NO_WARNINGS
#define MAX_LEN 101
#define DIR_LEN 4
#define POS 2
#define VISITED 1
#define X 0
#define Y 1
#include <stdio.h>
#include <stdlib.h>

int dx[DIR_LEN] = { -1, 0, 1, 0 };
int dy[DIR_LEN] = { 0, -1, 0, 1 };
int graph[MAX_LEN][MAX_LEN] = { 0, };
int visited[MAX_LEN][MAX_LEN] = { 0, };
int queue[MAX_LEN * MAX_LEN][POS] = { 0, };
int N, M, front = 0, rear = 0;

int sol(int x, int y) {
	visited[x][y] = 1;
	// enqueue
	queue[rear][X] = x;
	queue[rear][Y] = y;
	rear++;
	
	while (front < rear) {
		// dequeue
		int retX = queue[front][X];
		int retY = queue[front][Y];
		front++;

		for (int i = 0; i < DIR_LEN; i++) {
			int nx = retX + dx[i];
			int ny = retY + dy[i];
			if (nx > -1 && ny > -1 && nx < N && ny < M && visited[nx][ny] != VISITED && graph[nx][ny] != 0) {
				graph[nx][ny] = graph[retX][retY] + 1; 
				visited[nx][ny] = VISITED;
				queue[rear][X] = nx;
				queue[rear][Y] = ny;
				rear++;
			}
		}
	}
	return graph[N - 1][M - 1];
}

int main(void) {
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1d", &graph[i][j]);
		}
	}
	
	printf("%d", sol(0, 0));
	
	return 0;
}