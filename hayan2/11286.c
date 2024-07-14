#define _CRT_SECURE_NO_WARNINGS
#define	MAX_ELEMENTS 100001
#define ROOT 1
#include <stdio.h>
#include <stdlib.h>

// -2147483648 < N < 2147483648

typedef struct Node {
	int key;
	int abs;
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

Node* generateNode() {
	return (Node*)malloc(sizeof(Node));
}

void initHeap(Heap* heap) {
	heap->size = 0;
}

void initNode(Node* node, int x) {
	node->abs = (x < 0) ? ((x) * (-1)) : x;
	node->key = x;
}

void insert(Heap* heap, Node* node) {
	int idx = (++heap->size);

	while (idx != 1 && node->abs <= heap->heap[idx / 2]->abs) {
		if (node->abs == heap->heap[idx / 2]->abs && node->key > heap->heap[idx / 2]->key) {
			break;
		}
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
		if (child < heap->size && heap->heap[child]->abs >= heap->heap[child + 1]->abs) {
			if (heap->heap[child]->abs == heap->heap[child + 1]->abs) {
				if (heap->heap[child]->key > heap->heap[child + 1]->key) {
					child++;
				}
			}
			else {
				child++;
			}			
		}
		if (heap->heap[child]->abs >= tmp->abs) {			
			if (heap->heap[child]->abs == tmp->abs && heap->heap[child]->key > tmp->key) {
				break;
			}
			if (heap->heap[child]->abs > tmp->abs) {
				break;
			}			
		}		
		
		heap->heap[parent] = heap->heap[child];
		parent = child;
		child *= 2;
	}
	heap->heap[parent] = tmp;

	return ret;
}

void displayHeap(Heap* heap) {
	int flag = 1;
	for (int i = 1; i <= heap->size; i++) {
		if (i % flag == 0) {
			printf("\n");
			flag *= 2;
		}
		printf("i : [abs : %d], [key : %d] | ", heap->heap[i]->abs, heap->heap[i]->key);

	}
	printf("\n");

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