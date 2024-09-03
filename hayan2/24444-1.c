#define _CRT_SECURE_NO_WARNINGS
#define MAX_LEN 100002
#define INIT_VAL 2
#define IS_EMPTY 0
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	struct Node* link;
	int v;
}Node;

typedef struct Vector {
	int* arr;
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

void initQueue(Queue* queue) {
	queue->front = queue->rear = NULL;
	queue->size = 0;
}

void initNode(Node* node, int r) {
	node->link = NULL;
	node->v = r;
}

void initGraph(Vector* graph, int N) {
	for (int i = 1; i <= N; i++) {
		graph[i].arr = (int*)malloc(sizeof(int) * INIT_VAL);
		graph[i].size = 0;
		graph[i].capacity = INIT_VAL;
	}
}

void pushBack(Vector* graph, int u, int v) {
	if (graph[u].size < graph[u].capacity) {
		graph[u].arr[graph[u].size] = v;
	}
	else {
		int newSize = graph[u].capacity * 2;
		int* tmp = (int*)realloc(graph[u].arr, sizeof(int) * newSize);
		if (tmp != NULL) {
			graph[u].arr = tmp;
			graph[u].arr[graph[u].size] = v;
			graph[u].capacity = newSize;
		}
	}
	graph[u].size++;
}

void enQueue(Queue* queue, int r) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	initNode(newNode, r);

	if (queue->size == IS_EMPTY) {
		queue->front = newNode;
		queue->rear = newNode;
	}
	else {
		queue->rear->link = newNode;
		queue->rear = newNode;
	}

	queue->size++;
}

int deQueue(Queue* queue) {
	if (queue->size == IS_EMPTY) {
		return;
	}
	
	int ret = queue->front->v;

	queue->front = queue->front->link;
	queue->size--;

	return ret;
}

int compare(const void* a, const void* b) {
	return (*(int*)a - *(int*)b);
}

int visited[MAX_LEN] = { 0, };
int res[MAX_LEN] = { 0, };
int cnt = 0;

void BFS(Vector* graph, Queue* queue, int r) {
	if (visited[r] == 1) {
		return;
	}
	
	visited[r] = 1;	
	enQueue(queue, r);
	

	while (queue->size != IS_EMPTY) {
		int ret = deQueue(queue);
		cnt++;
		res[ret] = cnt;
		for (int i = 0; i < graph[ret].size; i++) {
			if (visited[graph[ret].arr[i]] == 0) {
				enQueue(queue, graph[ret].arr[i]);
				visited[graph[ret].arr[i]] = 1;
			}
		}
	}
}

int main(void) {
	int N, M, R, u, v;

	scanf("%d %d %d", &N, &M, &R);

	Vector* graph = generateGraph(N);
	Queue* queue = generateQueue();
	initGraph(graph, N);
	initQueue(queue);

	for (int i = 0; i < M; i++) {
		scanf("%d %d", &u, &v);

		pushBack(graph, u, v);
		pushBack(graph, v, u);
	}

	for (int i = 1; i <= N; i++) {
		qsort(graph[i].arr, graph[i].size, sizeof(int), compare);
	}
		
	BFS(graph, queue, R);

	for (int i = 1; i <= N; i++) {
		printf("%d\n", res[i]);
	}

	return 0;
}