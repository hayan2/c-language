#define _CRT_SECURE_NO_WARNINGS
#define MAX_LEN 100002
#define INIT_VAL 2
#define IS_EMPTY 0
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int v;
	struct Node* link;
}Node;

typedef struct Vector {
	Node* arr;
	int size;
	int capacity;
}Vector;

typedef struct Queue {
	Node* front;
	Node* rear;
	int size;
}Queue;

Vector* generateGraph(int N) {
	return (Vector*)malloc(sizeof(Vector) * N);
}

Queue* generateQueue() {
	return (Queue*)malloc(sizeof(Queue));
}

void initGraph(Vector* graph, int N) {
	for (int i = 1; i <= N; i++) {
		graph[i].arr = (Node*)malloc(sizeof(Node) * INIT_VAL);
		graph[i].size = 0;
		graph[i].capacity = INIT_VAL;
	}
}

void initQueue(Queue* queue) {
	queue->front = queue->rear = NULL;
	queue->size = 0;
}

void pushBack(Vector* graph, int u, int v) {
	if (graph[u].size < graph[u].capacity) {
		graph[u].arr[graph[u].size].v = v;
	}
	else {
		int newSize = graph[u].capacity * 2;
		Node* arr = (Node*)realloc(graph[u].arr, sizeof(Node) * newSize);
		if (arr != NULL) {
			graph[u].arr = arr;
			graph[u].arr[graph[u].size].v = v;
		}
		graph[u].capacity = newSize;
	}
	graph[u].size++;
}

int compare(const void* a, const void* b) {
	return (*(int*)a - *(int*)b);
}

void displayGraph(Vector* graph, int N) {
	for (int i = 1; i <= N; i++) {
		printf("graph[%d] : ", i);
		for (int j = 0; j < graph[i].size; j++) {
			printf("%d ", graph[i].arr[j].v);
		}
		printf("\n");
	}
}

void enQueue(Queue* queue, Node* node) {
	if (queue->size == IS_EMPTY) {
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
	if (queue->size == IS_EMPTY) {
		return;
	}
	
	Node* ret = queue->front;
	queue->front = queue->front->link;

	return ret;
}

int visited[MAX_LEN] = { 0, };
int res[MAX_LEN] = { 0, };
int cnt = 0;

void BFS(Vector* graph, int r) {
	if (visited[r] == 1) {
		return;
	}

	visited[r] = 1;
	cnt++;
	res[r] = cnt;

	for (int i = 1; i <= graph[r].size; i++) {
		BFS(graph, graph[r].arr[i].v);
	}
}

int main(void) {
	int N, M, R, u, v;

	scanf("%d %d %d", &N, &M, &R);

	Vector* graph = generateGraph(N);
	initGraph(graph, N);

	for (int i = 0; i < M; i++) {
		scanf("%d %d", &u, &v);

		pushBack(graph, u, v);
		pushBack(graph, v, u);
	}

	for (int i = 1; i <= N; i++) {
		qsort(graph[i].arr, graph[i].size, sizeof(Node), compare);
	}

	BFS(graph, R);

	for (int i = 1; i < N; i++) {
		printf("%d\n", res[i]);
	}

	return 0;
}