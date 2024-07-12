#define _CRT_SECURE_NO_WARNINGS
#define MAX_ELEMENT 100001
#define ROOT 1
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	int key;
}Node;

typedef struct Heap {
	Node* heap[MAX_ELEMENT];
	int root;
	int size;
}Heap;

Heap* generateHeap() {
	return (Heap*)malloc(sizeof(Heap));
}

void initHeap(Heap* heap) {
	heap->root = ROOT;
	heap->size = 0;
}

int isEmpty(Heap* heap) {
	return heap->size == 0;
}

void insert(Heap* heap, Node* node) {
	int idx = (++heap->size);

	while (idx != 1 && node->data > heap->heap[idx / 2]->data) {
		heap->heap[idx] = heap->heap[idx / 2];
		idx /= 2;
	}
	heap->heap[idx] = node;
}

Node* delete(Heap* heap) {
	Node* ret = heap->heap[1];
	Node* tmp = heap->heap[(heap->size)--];
	
	int parent = ROOT, child = 2;
	
	while (child <= heap->size) {
		if ((child < heap->size) && (heap->heap[child]->data) < heap->heap[child + 1]->data) {
			child++;
		}
		if (tmp->data >= heap->heap[child]->data) {
			break;
		}
		heap->heap[parent] = heap->heap[child];
		parent = child;
		child *= 2;
	}
	heap->heap[parent] = tmp;

	return ret;
}

void displayHeap(Heap* heap) {
	for (int i = 1; i <= heap->size; i++) {
		printf("%d : %d(%d) ", i, heap->heap[i]->data, heap->heap[i]->key);
	}
}

int main(void) {
	Heap* heap = generateHeap();
	initHeap(heap);

	int N, x;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &x);

		if (x != 0) {
			Node* node = (Node*)malloc(sizeof(Node));
			node->data = x;
			node->key = x;

			insert(heap, node);
		}
		else {
			if (!isEmpty(heap)) {
				printf("%d\n", delete(heap)->data);
			}
			else {
				printf("0\n");
			}
		}
	}

	// displayHeap(heap);

	return 0;
}