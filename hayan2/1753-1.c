#define _CRT_SECURE_NO_WARNINGS
#define MAX_LEN 20001
#define INF 2147483647
#define INIT 0
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
	struct Node* link;
	int v;
	int w;
}Node;

typedef struct Queue {
	Node* front;
	Node* rear;
	int size;
}Queue;

typedef struct Vector {
	Node* arr;
	int idx;
	int capacity;
}Vector;

Queue* generateQueue() {
	return (Queue*)malloc(sizeof(Queue));
}

Vector* generateGraph(int V) {
	return (Vector*)malloc(sizeof(Vector) * V);
}

void initGraph(Vector* graph, int V) {
	for (int i = 1; i <= V; i++) {
		graph[i].arr = (Node*)malloc(sizeof(Node) * (V + 1));
		graph[i].idx = INIT;
		graph[i].capacity = V;

		for (int j = 1; j <= V; j++) {
			graph[i].arr[j].v = INIT;
			graph[i].arr[j].w = INF;
		}
	}
}

void pushBack(Vector* graph, int u, int v, int w) {
	if (graph[u].idx + 1 < graph[u].capacity) {
		graph[u].arr[graph[u].idx].v = v;
		graph[u].arr[graph[u].idx].w = w;
	}
	else {
		int reSize = graph[u].capacity * 2;
		int* newGraph = (int*)realloc(graph[u].arr, sizeof(int) * reSize);
		if (newGraph != NULL) {
			graph[u].arr = newGraph;
			graph[u].arr[graph[u].idx].v = v;
			graph[u].arr[graph[u].idx].w = w;
		}
		graph[u].capacity = reSize;
	}
	graph[u].idx++;
}

int main(void) {
	int V, E, K;

	scanf("%d %d", &V, &E);
	scanf("%d", &K);

	int u, v, w;

	for (int i = 0; i < E; i++) {
		scanf("%d %d %d", &u, &v, &w);
	}

	return 0;
}