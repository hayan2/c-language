#define _CRT_SECURE_NO_WARNINGS
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
	queue->front = queue->rear = NULL;
	queue->size = 0;
}

int isQueueEmpty(Queue* queue) {
	return queue->size == 0;
}

void enQueue(Queue* queue, int data) {
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
	if (isQueueEmpty(queue)) {
		return -1;
	}

	int data = queue->front->data;

	queue->front = queue->front->link;
	queue->size--;

	return data;
}

int shuffleCard(Queue* queue) {
	Node* newNode = (Node*)malloc(sizeof(Node));

	queue->front = queue->front->link;
	queue->size--;
	
	if (queue->size == 1) {
		return queue->front->data;
	}
	newNode->data = queue->front->data;
	newNode->link = NULL;

	queue->front = queue->front->link;
	queue->rear->link = newNode;
	queue->rear = newNode;
	
	return queue->front->data;
}

void displayQueue(Queue* queue) {
	Node* newNode = (Node*)malloc(sizeof(Node));

	newNode = queue->front;
	for (int i = 0; i < queue->size; i++) {
		printf("%d ", newNode->data);
		newNode = newNode->link;
	}
	printf("\n");
}

int main(void) {
	Queue queue;
	int N, data, res = 0;

	scanf("%d", &N);

	if (N == 1) {
		printf("1");
		exit(0);
	}

	initQueue(&queue);

	for (int i = 1; i < N + 1; i++) {
		enQueue(&queue, i);
	}

	while (queue.size != 1) {		
		res = shuffleCard(&queue);
	}

	printf("%d", res);
	
	return 0;
}