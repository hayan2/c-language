#define _CRT_SECURE_NO_WARNINGS
#define ARRAY_SIZE 100001
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
	int data;
	struct Node* link;
}Node;

typedef struct QueueStack {
	// queue 0 stack 1
	int dataStrcutureType;
	Node* top;
	Node* front;
	Node* rear;
	int size;
}QueueStack;

int isDataStructureEmpty(QueueStack* queuestack) {
	return queuestack->size == 0;
}

void initQueueStack(QueueStack* queuestack) {
	queuestack->top = NULL;
	queuestack->front = NULL;
	queuestack->rear = NULL;
	queuestack->size = 0;	
}

void push(QueueStack* queuestack, int data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->link = NULL;

	if (isDataStructureEmpty(queuestack)) {
		queuestack->top = newNode;
	}
	else {
		newNode->link = queuestack->top;
		queuestack->top = newNode;
	}
	queuestack->size++;
}

void enQueue(QueueStack* queuestack, int data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->link = NULL;

	if (isDataStructureEmpty(queuestack)) {
		queuestack->front = newNode;
		queuestack->rear = newNode;		
	}
	else {
		queuestack->rear->link = newNode;
		queuestack->rear = newNode;
	}
	queuestack->size++;
}

int pop(QueueStack* queuestack) {

}

int deQueue(QueueStack* queuestack) {

}

void displayQueueStack(QueueStack* queuestack) {
	Node* newNode = (Node*)malloc(sizeof(Node));

	// queue
	if (queuestack->dataStrcutureType == 0) {
		newNode = queuestack->front;
		printf("| QUEUE | Front | ");
		for (int i = 0; i < queuestack->size; i++) {
			printf("%d -> ", newNode->data);
			newNode = newNode->link;
		}
		printf("| Rear |\n");
	}
	// stack
	else {
		newNode = queuestack->top;
		printf("| STACK |  Top  | ");
		for (int i = 0; i < queuestack->size; i++) {
			printf("%d -> ", newNode->data);
			newNode = newNode->link;
		}
		printf("|\n");
	}	
}

int main(void) {	
	int N, M, A, B;

	scanf("%d", &N);

	QueueStack* queuestack = (QueueStack*)malloc(sizeof(QueueStack) * N);
	
	for (int i = 0; i < N; i++) {
		scanf("%d", &A);
		queuestack[i].dataStrcutureType = A;
		initQueueStack(&queuestack[i]);
	}

	for (int i = 0; i < N; i++) {
		scanf("%d", &B);
		if (queuestack[i].dataStrcutureType == 0) {
			enQueue(&queuestack[i], B);
		}
		else {
			push(&queuestack[i], B);
		}
	}

	scanf("%d", &M);

	for (int i = 0; i < M; i++) {
		if (queuestack[i].dataStrcutureType == 1) {
			continue;
		}


	}

	return 0;
}
