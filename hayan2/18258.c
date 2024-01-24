#define _CRT_SECURE_NO_WARNINGS
#define COMMAND_SIZE 7
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

int returnQueueSize(Queue* queue) {
	return queue->size;
}

int returnQueueFrontData(Queue* queue) {
	if (isQueueEmpty(queue)) {
		return -1;
	}
	else {
		return queue->front->data;
	}
}

int returnQueueRearData(Queue* queue) {
	if (isQueueEmpty(queue)) {
		return -1;
	}
	else {
		return queue->rear->data;
	}
}

int main(void) {
	char command[COMMAND_SIZE];
	Queue queue;
	int N, data;

	scanf("%d", &N);

	initQueue(&queue);

	for (int i = 0; i < N; i++) {
		scanf("%s", command);

		if (strcmp(command, "push") == 0) {
			scanf("%d", &data);
			enQueue(&queue, data);
		}
		else if (strcmp(command, "pop") == 0) {
			printf("%d\n", deQueue(&queue));
		}
		else if (strcmp(command, "size") == 0) {
			printf("%d\n", returnQueueSize(&queue));
		}
		else if (strcmp(command, "empty") == 0) {
			printf("%d\n", isQueueEmpty(&queue));
		}
		else if (strcmp(command, "front") == 0) {
			printf("%d\n", returnQueueFrontData(&queue));
		}
		else if (strcmp(command, "back") == 0) {
			printf("%d\n", returnQueueRearData(&queue));
		}
	}

	return 0;
}