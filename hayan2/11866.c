#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int josephus[1001];
int josephusIndex = 0;

typedef struct Node {
	int data;
	struct Node* link;
}Node;

typedef struct Queue {
	Node* front;
	Node* rear;
	Node* current;
	Node* previous;
	int size;
}Queue;

int isQueueEmpty(Queue* queue) {
	return queue->size == 0;
}

void initQueue(Queue* queue) {
	queue->front = NULL;
	queue->rear = NULL;
	queue->current = NULL;
	queue->previous = NULL;
	queue->size = 0;
}

void enQueue(Queue* queue, int data, int endSign) {
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
		if (endSign == 1) {
			newNode->link = queue->front;
			queue->current = queue->front;
			queue->previous = queue->rear;
		}
	}

	queue->size++;
}

int deQueue(Queue* queue) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode = queue->current;

	return;
}

void getJosephusQuestion(Queue* queue, int N, int K) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < K - 1; j++) {
			queue->current = queue->current->link;
			queue->previous = queue->previous->link;
		}
		josephus[josephusIndex++] = queue->current->data;
		queue->previous->link = queue->current->link;
		queue->current = queue->current->link;
	}
}

int displayQueue(Queue* queue) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode = queue->front;
	for (int i = 0; i < queue->size; i++) {
		printf("| Data from current node : %d, LINK : %d |\n", newNode->data, newNode->link->data);
		newNode = newNode->link;
	}
}



int main(void) {
	Queue queue;
	int N, K;

	initQueue(&queue);

	scanf("%d %d", &N, &K);

	if (N == 1) {
		printf("<1>");
		exit(0);
	}

	for (int i = 1; i < N + 1; i++) {
		if (N == i) {
			enQueue(&queue, i, 1);
		}
		else {
			enQueue(&queue, i, 0);
		}
	}

	getJosephusQuestion(&queue, N, K);
		
	for (int i = 0; i < N; i++) {
		if (i == 0) {
			printf("<%d, ", josephus[i]);
		}
		else if (i == N - 1) {
			printf("%d>", josephus[i]);
		}
		else {
			printf("%d, ", josephus[i]);
		}
	}

	return 0;
}