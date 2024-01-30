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

int isQueueEmpty(Queue* queue) {
	return queue->size == 0;
}

void initQueue(Queue* queue) {
	queue->front = NULL;
	queue->rear = NULL;
	queue->size = 0;
}

void enQueue(Queue* queue, int data, int endSign) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	if (endSign == 0) {
		if (isQueueEmpty(queue)) {

		}
		else {

		}
	}
	else {

	}
}

Node* deQueue(Queue* queue) {

}

int main(void) {
	Queue queue;
	Queue josephus;
	int N, K;

	scanf("%d %d", &N, &K);

	initQueue(&queue);

	for (int i = 0; i < N; i++) {
		int data;
		scanf("%d", &data);
		if (i == N - 1) {
			enQueue(&queue, data, 1);
		}
		else {
			enQueue(&queue, data, 0);
		}
		
	}

	return 0;
}