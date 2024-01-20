#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Node {
	int num;
	struct Node* link;
}Node;

typedef struct Stack {
	Node* top;
	int count;
}Stack;

typedef struct Queue {
	Node* front;
	Node* rear;
	int count;
}Queue;

int isStackEmpty(Stack* stack) {
	return stack->count == 0;
}

int isQueueEmpty(Queue* queue) {
	return queue->count == 0;
}

void initNode(Node* node, int data) {
	node->num = data;
	node->link = NULL;
}

void initStack(Stack* stack) {
	stack->top = NULL;
	stack->count = 0;
}

void initQueue(Queue* queue) {
	queue->front = NULL;
	queue->rear = NULL;
	queue->count = 0;
}

void enQueue(Queue* queue, int data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	initNode(newNode, data);

	if (isQueueEmpty(queue)) {
		queue->front = newNode;
		queue->rear = newNode;
	}
	else {
		queue->rear->link = newNode;
		queue->rear = newNode;
	}
	queue->count++;
}

void push(Stack* stack, int data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	initNode(newNode, data);

	if (isStackEmpty(stack)) {
		stack->top = newNode;
	}
	else {
		newNode->link = stack->top;
		stack->top = newNode;
	}
	stack->count++;
}

void displayStack(Stack* stack) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode = stack->top;
	for (int i = 0; i < stack->count; i++) {
		printf("%d", newNode->num);
		newNode = newNode->link;
	}
}

void displayQueue(Queue* queue) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode = queue->front;
	for (int i = 0; i < queue->count; i++) {
		printf("%d ", newNode->num);
		newNode = newNode->link;
	}
}

bool getResult(Queue* queue, Stack* stack) {
	int count = 1;

	int length = queue->count;	
	for (int i = 0; i < length * length; i++) {
		if (!isQueueEmpty(queue) && count == queue->front->num) {
			queue->front = queue->front->link;
			queue->count--;
			count++;
		}
		else {
			if (!isStackEmpty(stack) && count == stack->top->num) {
				stack->top = stack->top->link;
				stack->count--;
				count++;
			}
			else if (!isStackEmpty(stack) && count != stack->top->num && isQueueEmpty(queue)) {
				return false;
			}
			else {
				if (!isQueueEmpty(queue)) {
					push(stack, queue->front->num);
					queue->front = queue->front->link;
					queue->count--;
				}
			}
		}
	}

	return true;
}

int main(void) {
	int N;
	Queue queue;
	Stack stack;	

	scanf("%d", &N);

	initStack(&stack);
	initQueue(&queue);

	for (int i = 0; i < N; i++) {
		int data;
		scanf("%d", &data);
		enQueue(&queue, data);
	}
	
	printf("%s", (getResult(&queue, &stack) ? "Nice" : "Sad"));

	return 0;
}