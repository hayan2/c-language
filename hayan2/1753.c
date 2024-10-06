#define _CRT_SECURE_NO_WARNINGS
#define MAX_V 20005
#define MAX_E 300005
#define INF 1e9
#define ROOT 1
#define VISITED 1
#define EMPTY 0
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Edge {
	// origin destination weight
	int u, v, w;
	// link
	int prev;
}Edge;

typedef struct Heap {
	// destination weight
	int v, w;
}Heap;

Edge edge[MAX_E];
Heap heap[MAX_E];
int res[MAX_V];
int pos[MAX_V] = { 0, };
int visited[MAX_V] = { 0, };
int idx = 0;
int V, E;

void swap(Heap* a, Heap* b) {
	Heap tmp = *a;
	*a = *b;
	*b = tmp;
}

void push(Heap x) {
	heap[++idx] = x;

	while (idx != 1 && x.w < heap[idx / 2].w) {
		swap(&x, &heap[idx / 2]);
	}
}

Heap pop() {
	Heap ret = heap[ROOT];
	heap[ROOT] = heap[idx--];

	int parent = ROOT, child = ROOT + 1;

	while (child <= idx) {
		if (heap[child].w < heap[parent].w) {
			break;
		}
		if (child < idx && heap[child].w > heap[child + 1].w) {
			child++;
		}
		swap(&heap[parent], &heap[child]);
		parent = child;
		child *= 2;
	}

	return ret;
}

void sol(int K) {
	for (int i = 1; i <= V; i++) {
		res[i] = INF;
	}

	res[K] = 0;	
	push((Heap) { K, 0 });

	while (idx > 0) {
		Heap ret = pop();

		if (visited[ret.v] == VISITED) {
			continue;
		}
		visited[ret.v] = VISITED;

		if (ret.w > res[ret.v]) {
			continue;
		}

		for (int i = pos[ret.v]; i; i = edge[i].prev) {
			if (res[edge[i].v] > res[ret.v] + edge[i].w) {
				res[edge[i].v] = res[ret.v] + edge[i].w;
				push((Heap) { edge[i].v, res[edge[i].v] });
			}
		}
	}
}

int main(void) {
	int K;

	scanf("%d %d %d", &V, &E, &K);

	for (int i = 1; i <= E; i++) {
		scanf("%d %d %d", &edge[i].u, &edge[i].v, &edge[i].w);
		edge[i].prev = pos[edge[i].u];
		pos[edge[i].u] = i;
	}

	sol(K);

	for (int i = 1; i <= V; i++) {
		res[i] == INF ? puts("INF") : printf("%d\n", res[i]);
	}

	return 0;
}