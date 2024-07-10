#define _CRT_SECURE_NO_WARNINGS
#define ARRAY_LEN 100001
#include <stdio.h>
#include <stdlib.h>

typedef struct Heap {
	struct Node* front;
	struct Node* rear;
	struct Node* max;
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
	newNode->prev = NULL;
	newNode->next = NULL;
	newNode->prevMax = NULL;	

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
			findInsert(heap, newNode);
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

int findInsert(Heap* heap, Node* node) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	int key = node->x;

	newNode = heap->max;
	for (int i = 0; i < heap->count; i++) {
		if (newNode->prevMax != NULL) {
			if (key >= newNode->prevMax->x && key <= newNode->x) {
				node->prevMax = newNode->prevMax;
				newNode->prevMax = node;
				break;
			}
		}
		else {
			if (key <= newNode->x) {
				newNode->prevMax = node;
			}
			break;
		}

		newNode = newNode->prevMax;
	}	
	return key;
}

void displayHeap(Heap* heap) {
	printf("\nDISPLAY HEAP\n");
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode = heap->front;

	for (int i = 0; i < heap->count; i++) {
		printf("%d ", newNode->x);
		newNode = newNode->next;
	}
}

void displayMaxHeap(Heap* heap) {
	printf("\nDISPLAY MAX HEAP\n");
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode = heap->max;

	for (int i = 0; i < heap->count; i++) {
		printf("%d ", newNode->x);
		newNode = newNode->prevMax;
	}
}

int pop(Heap* heap) {
	Node* newNode = (Node*)malloc(sizeof(Node));	
	int ret = 0;

	if (isEmpty(heap)) {
		ret = 0;
	}
	else {
		newNode = heap->max;
		heap->count--;

		ret = newNode->x;		

		if (newNode->prev == NULL && newNode->next == NULL) {
			heap->max = NULL;
			heap->rear = NULL;
			heap->front = NULL;

			return ret;
		}
		if (newNode->prev == NULL) {
			newNode->next->prev = NULL;
			heap->max = heap->max->prevMax;

			return ret;
		}
		if (newNode->next == NULL) {
			newNode->prev->next = NULL;
			heap->max = heap->max->prevMax;

			return ret;
		}
		if (newNode->prev != NULL && newNode->next != NULL) {
			newNode->prev->next = newNode->next;
			newNode->next->prev = newNode->prev;
		}
	}

	heap->max = heap->max->prevMax;

	return ret;
}

int main(void) {
	Heap heap;
	int N, x;

	scanf("%d", &N);

	initHeap(&heap);

	for (int i = 0; i < N; i++) {
		scanf("%d", &x);

		if (x != 0) {
			push(&heap, x);
		}
		else {
			printf("pop : [%d]\n", pop(&heap));			
			displayHeap(&heap);
			displayMaxHeap(&heap);
			printf("\n");
		}
	}

	return 0;
}
