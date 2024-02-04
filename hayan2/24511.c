#define _CRT_SECURE_NO_WARNINGS
#define ARRAY_SIZE 100001
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
	int data;
	struct Node* link;
}Node;

typedef struct Queue {
	Node* front;
	Node* rear;
	int size;
}Queue;

void initQueue(Queue* queue) {
	queue->front = NULL;
	queue->rear = NULL;
	queue->size = 0;
}

int isQueueEmpty(Queue* queue) {
	return queue->size == 0;
}

void enQueueToFront(Queue* queue, int data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->link = NULL;

	if (isQueueEmpty(queue)) {
		queue->front = newNode;
		queue->rear = newNode;
	}
	else {
		newNode->link = queue->front;
		queue->front = newNode;
	}
	queue->size++;
}

void enQueueToRear(Queue* queue, int data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->link = NULL;

	if (isQueueEmpty(queue)) {
		queue->front = newNode;
		queue->rear = newNode;
	}
	else {
		queue->rear->link = newNode;
		queue->rear = newNode;
	}
	queue->size++;
}

int deQueue(Queue* queue) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode = queue->front;
	int data = newNode->data;

	queue->front = queue->front->link;
	queue->size--;

	free(newNode);

	return data;
}

int main(void) {
	Queue* queue = (Queue*)malloc(sizeof(Queue));
	int flag[ARRAY_SIZE] = { 0, };
	int N, M, A, B, C;

	initQueue(queue);
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &A);
		if (A == 0) {
			flag[i] = 1;
		}
	}

	for (int i = 0; i < N; i++) {
		scanf("%d", &B);
		if (flag[i] == 1) {
			enQueueToFront(queue, B);
		}
	}

	scanf("%d", &M);

	for (int i = 0; i < M; i++) {
		scanf("%d", &C);
		enQueueToRear(queue, C);
		int res = deQueue(queue);
		printf("%d ", res);
	}

	return 0;
}