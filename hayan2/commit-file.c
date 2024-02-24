#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node* link;
}Node;

typedef struct Queue {
	int capacity;
	Node* front;
	Node* rear;
}Queue;

void isQueueEmpty(Queue* queue) {
	return queue->capacity == 0;
}

void initQueue(Queue* queue) {
	queue->capacity = 0;
	queue->front = NULL;
	queue->rear = NULL;
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

	queue->capacity++;
}

int deQueue(Queue* queue) {
	int data;
	if (isQueueEmpty(newNode)) {
		return -1;
	}
	else {
		data = queue->front->data;
		queue->front = queue->front->link;
	}

	return data;
}

void displayQueue(Queue* queue) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	for (int i = 0; i < queue->capacity; i++) {

	}

}

int main(void) {


	return 0;
}