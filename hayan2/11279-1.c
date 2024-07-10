#define _CRT_SECURE_NO_WARNINGS
#define ARRAY_LEN 100001
#include <stdio.h>
#include <stdlib.h>

typedef struct Heap {
	Node* front;
	Node* rear;
	Node* max;	
	int count;
}Heap;

typedef struct Node {
	int x;
	struct Node* prev;
	struct Node* next;
	struct Node* prevMax;
}Node;

int isEmpty(Heap* heap) {
	return (heap->count == 0);
}

void initHeap(Heap* heap) {
	heap->front = heap->rear = heap->max = NULL;
	heap->count = 0;
}

void push(Heap* heap, int x) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->x = x;

	if (isEmpty(heap)) {
		heap->front = newNode;
		heap->rear = newNode;
		heap->max = newNode;
		newNode->next = NULL;
		newNode->prev = NULL;
		newNode->prevMax = NULL;
	}
	else {
		if (heap->max->x > newNode->x) {
			
		}
		else {
			newNode->prevMax = heap->max;
			heap->max = newNode;
		}
		newNode->prev = heap->rear;
		heap->rear->next = newNode;
		heap->rear = newNode;
	}

	heap->count++;
}

void findInsert(Heap* heap, Node* node) {

}

int pop(Heap* heap) {
	int x;

	if (isEmpty(heap)) {
		x = 0;
	}
	else {
		
	}

	return 
}

int main(void) {
	Heap heap;
	int N, x;

	scanf("%d", &N);

	initHeap(&heap);

	for (int i = 0; i < N; i++) {
		scanf("%d", &x);

		if (x != 0) {
			
		}
		else {
			
		}

		printf("\n");
	}

	return 0;
}
