#define _CRT_SECURE_NO_WARNINGS
#define MAX_LEN 100002
#define INIT_VAL 3
#define ull unsigned long long
#include <stdio.h>
#include <stdlib.h>


// 11060kb | 104ms
typedef struct Vector {
	int* arr;
	int size;
	int capacity;
}Vector;

Vector* generateGraph(int N) {
	return (Vector*)malloc(sizeof(Vector) * N);
}

int compare(const void* a, const void* b) {
	const int* A = a, * B = b;
	return (*A > *B) - (*A < *B);
}

void initGraph(Vector* graph, int N) {
	for (int i = 1; i <= N; i++) {
		graph[i].arr = (int*)malloc(sizeof(int) * INIT_VAL);
		graph[i].size = 0;
		graph[i].capacity = INIT_VAL;
	}
}

void pushBack(Vector* graph, int u, int v) {
	if (graph[u].size + 1 < graph[u].capacity) {
		graph[u].arr[graph[u].size] = v;
	}
	else {
		int newSize = graph[u].capacity * 2;
		int* newGraph = (int*)realloc(graph[u].arr, sizeof(int) * newSize);
		if (newGraph != NULL) {
			graph[u].arr = newGraph;
			graph[u].arr[graph[u].size] = v;
		}
		graph[u].capacity = newSize;
	}
	graph[u].size++;
}

int visited[MAX_LEN] = { 0, };
int res[MAX_LEN] = { 0, };
int cnt = 0;

void DFS(Vector* graph, int r) {
	if (visited[r] == 1) {
		return;
	}

	visited[r] = 1;
	cnt++;
	res[r] = cnt;

	for (int i = 0; i < graph[r].size; i++) {
		DFS(graph, graph[r].arr[i]);
	}
}

int main(void) {
	int N, M, R, u, v;

	scanf("%d %d %d", &N, &M, &R);

	Vector* graph = generateGraph(N);

	initGraph(graph, N);

	for (int i = 1; i <= M; i++) {
		scanf("%d %d", &u, &v);

		pushBack(graph, u, v);
		pushBack(graph, v, u);
	}

	for (int i = 1; i <= N; i++) {
		qsort(graph[i].arr, graph[i].size, sizeof(int), compare);
	}

	DFS(graph, R);

	for (int i = 1; i <= N; i++) {
		printf("%d\n", res[i]);
	}

	return 0;
}