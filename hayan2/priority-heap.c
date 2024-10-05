#define _CRT_SECURE_NO_WARNINGS
#define MAX_ELEMENTS 100001
#define ROOT 1
#include <stdio.h>
#include <stdlib.h>

// MIN HEAP

typedef struct Node {
	int key;
}Node;

typedef struct Heap {
	Node* heap[MAX_ELEMENTS];
	int size;
}Heap;

int isEmpty(Heap* heap) {
	return heap->size == 0;
}

Heap* generateHeap() {
	return (Heap*)malloc(sizeof(Heap));
}

void initHeap(Heap* heap) {
	heap->size = 0;
}

Node* generateNode() {
	return (Node*)malloc(sizeof(Node));
}

void initNode(Node* node, int x) {
	node->key = x;
}

void insert(Heap* heap, Node* node) {
	int idx = (++heap->size);

	while (idx != 1 && node->key < heap->heap[idx / 2]->key) {
		heap->heap[idx] = heap->heap[idx / 2];
		idx /= 2;
	}

	heap->heap[idx] = node;
}

Node* delete(Heap* heap) {
	Node* ret = heap->heap[ROOT];
	Node* tmp = heap->heap[(heap->size)--];

	int parent = ROOT, child = ROOT + 1;

	while (child <= heap->size) {
		if ((child < heap->size) && (heap->heap[child]->key) > (heap->heap[child + 1]->key)) {
			child++;
		}
		if (heap->heap[child]->key >= tmp->key) {
			break;
		}
		heap->heap[parent] = heap->heap[child];
		parent = child;
		child *= 2;
	}

	heap->heap[parent] = tmp;

	return ret;
}

int main(void) {
	Heap* heap = generateHeap();
	initHeap(heap);

	int N, x;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &x);

		if (x != 0) {
			Node* node = generateNode();
			initNode(node, x);
			insert(heap, node);
		}
		else {
			if (!isEmpty(heap)) {
				printf("%d\n", delete(heap)->key);
			}
			else {
				printf("0\n");
			}
		}
	}

	return 0;
}