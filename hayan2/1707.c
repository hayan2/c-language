#define _CRT_SECURE_NO_WARNINGS
#define INIT_VAL 3
#define NON_COLOR -1
#define RED 0
#define BLUE 1
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int v;
	int color;
}Node;

typedef struct Vector {
	Node* arr;
	int idx;
	int capacity;
}Vector;

Vector* generateGraph(int V) {
	return (Vector*)malloc(sizeof(Vector) * V);
}

void initGraph(Vector* graph, int V) {
	for (int i = 1; i <= V; i++) {
		graph[i].arr = (Node*)malloc(sizeof(Node) * INIT_VAL);
		graph[i].idx = 0;
		graph[i].capacity = INIT_VAL;
	}
}

void pushBack(Vector* graph, int u, int v) {
	if (graph[u].idx + 1 < graph[u].capacity) {
		graph[u].arr[graph[u].idx].v = v;
	}
	else {
		int reSize = graph[u].capacity * 2;
		Node* newGraph = (Node*)realloc(graph[u].arr, sizeof(Node) * reSize);
		if (newGraph != NULL) {
			graph[u].arr = newGraph;
			graph[u].arr[graph[u].idx].v = v;
		}

		graph[u].capacity = reSize;
	}
	graph[u].arr[graph[u].idx].color = NON_COLOR;
	graph[u].idx++;
}

int main(void) {
	int K, V, E;

	scanf("%d", &K);
	
	while (K--) {
		scanf("%d %d", &V, &E);

		Vector* graph = generateGraph(V);
		initGraph(graph, V);

		int u, v;

		for (int i = 0; i < E; i++) {
			scanf("%d %d", &u, &v);

			pushBack(graph, u, v);
			pushBack(graph, v, u);

		}
	}

	return 0;
}