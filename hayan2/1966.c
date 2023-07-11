#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// acmicpc.net 1966

typedef struct Node {
	int data;
	struct Node* next;
}Node;

typedef struct Queue {
	Node* front;
	Node* rear;
	int count;
}Queue;

int isEmpty(Queue* queue) {
	return queue->count == 0;
}

void initQueue(Queue* queue) {
	queue->front = NULL;
	queue->rear = NULL;
	queue->count = 0;
}

void enQueue(Queue* queue, int data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL;

	if (isEmpty(queue)) {		
		queue->front = newNode;		
	}
	else {
		queue->rear->next = newNode;		
	}
	queue->rear = newNode;
	queue->count++;
}

void deQueue(Queue* queue) {
	if (isEmpty(queue)) {
		return;
	}	
	queue->front = queue->front->next;
	queue->count--;
}

void passed(Queue* queue) {	
	queue->rear->next = queue->front;
	queue->rear = queue->front;	
	queue->front = queue->front->next;
	queue->rear->next = NULL;
}

int checkPriority(Queue* queue) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode = queue->front->next;
	int data = queue->front->data;	
 
	for (int i = 0; i < (queue->count - 1); i++) {
		if (newNode->data > data) {
			return 1;
		}
		newNode = newNode->next;
	}

	return 0;
} 

Node* findingTargetNode(Queue* queue, int index) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode = queue->front;

	for (int i = 0; i < index; i++) {
		newNode = newNode->next;
	}

	return newNode;
}

int checkTarget(Queue* queue, int target) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	Node* targetNode = (Node*)malloc(sizeof(Node));
	
	targetNode = findingTargetNode(queue, target);

	newNode = queue->front;
	int cnt = 1;

	while (1) {
		if (checkPriority(queue)) {
			passed(queue);
		}
		else {
			if (queue->front == targetNode) {
				return cnt;
			}
			else {
				deQueue(queue);
				cnt++;
			}
		}
	}
}

void display(Queue* queue) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode = queue->front;

	for (int i = 0; i < queue->count; i++) {		
		printf("%d", newNode->data);
		newNode = newNode->next;
	}
	printf("\n");
}

int main(void) {	
	int data;

	int T;

	scanf("%d", &T);

	for (int i = 0; i < T; i++) {
		int n, target, data;
		Queue queue;

		scanf("%d %d", &n, &target);
		initQueue(&queue);

		for (int j = 0; j < n; j++) {
			scanf("%d", &data);
			enQueue(&queue, data);
			
		}
		printf("%d\n", checkTarget(&queue, target));
	}

	return 0;
}