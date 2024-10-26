#define _CRT_SECURE_NO_WARNINGS
#define MAX_LEN 1001
#define CRUSHED 1
#define DIR 4
#define WALL 1
#define VISITED 1
#define DIM 2
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
	int x;
	int y;	
	int crush;
	struct Node* link;
}Node;

typedef struct Queue {
	Node* front;
	Node* rear;
	int size;
}Queue;

int dx[DIR] = { -1, 0, 1, 0 };
int dy[DIR] = { 0, -1, 0, 1 };
int graph[MAX_LEN][MAX_LEN] = { 0, };
int cache[MAX_LEN][MAX_LEN] = { 0, };
int visited[MAX_LEN][MAX_LEN][DIM] = {0,};
int N, M;

Queue* generateQueue() {
	return (Queue*)malloc(sizeof(Queue));
}

Node* generateNode(int x, int y, int crush) {
	Node* ret = (Node*)malloc(sizeof(Node));

	ret->x = x;
	ret->y = y;
	ret->crush = crush;
	ret->link = NULL;

	return ret;
}

int isEmpty(Queue* queue) {
	return queue->size == 0;
}

void initQueue(Queue* queue) {
	queue->front = queue->rear = NULL;
	queue->size = 0;
}

void enQueue(Queue* queue, Node* node) {
	if (isEmpty(queue)) {
		queue->front = node;
		queue->rear = node;
	}
	else {
		queue->rear->link = node;
		queue->rear = node;
	}
	queue->size++;
}

Node* deQueue(Queue* queue) {
	if (isEmpty(queue)) {
		return;
	}

	Node* ret = queue->front;
	queue->front = queue->front->link;
	queue->size--;

	return ret;
}

int sol(Queue* queue, int x, int y, int crush) {
	Node* start = generateNode(x, y, crush);
	enQueue(queue, start);
	visited[x][y][start->crush] = VISITED;

	while (!isEmpty(queue) && cache[N - 1][M - 1] == 0) {
		Node* ret = deQueue(queue);
		int rx = ret->x;
		int ry = ret->y;

		for (int i = 0; i < DIR; i++) {
			int nx = rx + dx[i];
			int ny = ry + dy[i];

			if (nx < 0 || ny < 0 || nx >= N || ny >= M) {
				continue;
			}
			if (ret->crush && graph[nx][ny]) {
				continue;
			}

			Node* newNode = generateNode(nx, ny, ret->crush);
			if (graph[nx][ny] != WALL && visited[nx][ny][newNode->crush] != VISITED) {
				visited[nx][ny][newNode->crush] = VISITED;
				cache[nx][ny] = cache[rx][ry] + 1;
				enQueue(queue, newNode);
			}

			if (graph[nx][ny] == WALL && newNode->crush != CRUSHED && visited[nx][ny][newNode->crush + 1] != VISITED) {
				visited[nx][ny][newNode->crush + 1] = VISITED;
				cache[nx][ny] = cache[rx][ry] + 1;
				newNode->crush = CRUSHED;
				enQueue(queue, newNode);
			}
		}

		free(ret);
	}

	if (cache[N - 1][M - 1] == 0) {
		return -1;
	}

	return cache[N - 1][M - 1] + 1;
}

int main(void) {
	scanf("%d %d", &N, &M);
	Node* queue = generateQueue();
	initQueue(queue);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1d", &graph[i][j]);
		}
	}

	if (N == 1 && M == 1) {
		printf("1");
		exit(0);
	}

	printf("%d", sol(queue, 0, 0, 0));

	return 0;
}