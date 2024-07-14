#define _CRT_SECURE_NO_WARNINGS
#define MAX_ELEMENTS 100001
#define ROOT 1
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	int key;
}Node;

typedef struct Heap {
	Node* heap[MAX_ELEMENTS];	
	int size;
}Heap;

Heap* generateHeap() {
	return (Heap*)malloc(sizeof(Heap));
}

void initHeap(Heap* heap) {	
	heap->size = 0;
}

void initNode(Node* node, int x) {
	node->data = x;
	node->key = x;
}

int isEmpty(Heap* heap) {
	return heap->size == 0;
}

Node* generateNode(int x) {
	Node* node = (Node*)malloc(sizeof(Node));
	initNode(node, x);

	return node;
}

void insert(Heap* heap, Node* node) {
	int idx = (++heap->size);

	while (idx != 1 && node->key > heap->heap[idx / 2]->key) {
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
		if ((child < heap->size) && (heap->heap[child + 1]->key) > (heap->heap[child]->key)) {
			child++;
		}
		if (tmp->key >= heap->heap[child]->key) {
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
		printf("[%d] - %d \n", i, heap->heap[i]->key);
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
			insert(heap, generateNode(x));			
		}
		else {
			if (isEmpty(heap)) {
				printf("0\n");
			}
			else {
				printf("%d\n", delete(heap)->key); 				
			}			
		}
	}


	return 0;
}