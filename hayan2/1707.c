#define _CRT_SECURE_NO_WARNINGS
#define MAX_LEN 20001
#define VISITED 1
#define INIT_VAL 3
#define NON_COLOR -1
#define START 1
#define RED 0
#define BLUE 1
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// failed

typedef struct Node {
	struct Node* link;
	int v;
}Node;

typedef struct Vector {
	int* arr;
	int idx;
	int capacity;
}Vector;

typedef struct Queue {
	Node* front;
	Node* rear;
	int size;
}Queue;

Vector* generateGraph(int V) {
	return (Vector*)malloc(sizeof(Vector) * V);
}

Queue* generateQueue() {
	return (Queue*)malloc(sizeof(Queue));
}

void initGraph(Vector* graph, int V) {
	for (int i = 1; i <= V; i++) {
		graph[i].arr = (int*)malloc(sizeof(int) * INIT_VAL);
		graph[i].idx = 0;
		graph[i].capacity = INIT_VAL;
	}
}

void initQueue(Queue* queue) {
	queue->front = queue->rear = NULL;
	queue->size = 0;
}

int isEmpty(Queue* queue) {
	return queue->size == 0;
}

void enQueue(Queue* queue, int v) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->v = v;
	node->link = NULL;

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

void pushBack(Vector* graph, int u, int v) {
	if (graph[u].idx + 1 < graph[u].capacity) {
		graph[u].arr[graph[u].idx] = v;
	}
	else {
		int reSize = graph[u].capacity * 2;
		int* newGraph = (int*)realloc(graph[u].arr, sizeof(int) * reSize);
		if (newGraph != NULL) {
			graph[u].arr = newGraph;
			graph[u].arr[graph[u].idx] = v;
		}

		graph[u].capacity = reSize;
	}
	graph[u].idx++;
}

int visited[MAX_LEN] = { 0, };
int color[MAX_LEN];

bool BFS(Vector* graph, Queue* queue) {
	if (visited[START] == VISITED) {
		return false;
	}

	visited[START] = VISITED;
	color[START] = RED;
	enQueue(queue, START);

	while (!isEmpty(queue)) {
		Node* ret = deQueue(queue);
		
		for (int i = 0; i < graph[ret->v].idx; i++) {
			if (color[ret->v] == color[graph[ret->v].arr[i]]) {
				return false;
			}

			if (visited[graph[ret->v].arr[i]] != VISITED) {
				enQueue(queue, graph[ret->v].arr[i]);
				visited[graph[ret->v].arr[i]] = VISITED;
				color[graph[ret->v].arr[i]] = color[ret->v] ? RED : BLUE;
			}
		}
		free(ret);
	}

	return true;
}

int compare(const void* a, const void* b) {
	return (*(int*)a - *(int*)b);
}

void displayGraph(Vector* graph, int V) {
	for (int i = 1; i <= V; i++) {
		printf("%d : ", i);
		for (int j = 0; j < graph[i].idx; j++) {
			printf("%d ", graph[i].arr[j]);
		}
		printf("\n");
	}
}

int main(void) {
	int K, V, E;

	scanf("%d", &K);
	
	while (K--) {
		scanf("%d %d", &V, &E);

		Vector* graph = generateGraph(V);
		Queue* queue = generateQueue();		
		initGraph(graph, V);
		initQueue(queue);

		int u, v;

		for (int i = 0; i < E; i++) {
			scanf("%d %d", &u, &v);

			pushBack(graph, u, v);
			pushBack(graph, v, u);
		}

		for (int i = 1; i <= V; i++) {
			qsort(graph[i].arr, graph[i].idx, sizeof(int), compare);
		}
		displayGraph(graph, V);
		
		memset(color, -1, sizeof(color));		
		printf("%s\n", BFS(graph, queue) ? "YES" : "NO");
		memset(visited, 0, sizeof(visited));
	}

	return 0;
}