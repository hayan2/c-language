#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	int index;
	struct Node* next;
	struct Node* previous;
}Node;

typedef struct Dequeue {
	Node* front;
	Node* rear;
	Node* current;
	int size;
}Dequeue;

void initDequeue(Dequeue* dequeue) {
	dequeue->front = NULL;
	dequeue->rear = NULL;
	dequeue->current = NULL;
	dequeue->size = 0;
}

int isDequeueEmpty(Dequeue* dequeue) {
	return dequeue->size == 0;
}

void addToRear(Dequeue* dequeue, int data, int index, int endSign) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->index = index;
	newNode->next = NULL;
	newNode->previous = NULL;

	if (isDequeueEmpty(dequeue)) {
		dequeue->front = newNode;
		dequeue->rear = newNode;
	}
	else {
		newNode->previous = dequeue->rear;
		dequeue->rear->next = newNode;
		dequeue->rear = newNode;
		if (endSign == 1) {
			newNode->next = dequeue->front;
			dequeue->front->previous = dequeue->rear;
			dequeue->current = dequeue->front;
		}
	}
	dequeue->size++;
}

int displayDequeue(Dequeue* dequeue) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode = dequeue->current;

	printf("\n");
	for (int i = 0; i < dequeue->size; i++) {
		if (newNode->previous == NULL && newNode->next != NULL) {
			printf("| Data from current node : %d, Previous node data : NULL, Next node data : %d |\n", newNode->data, newNode->next->data);
			newNode = newNode->next;
		}
		else if (newNode->previous != NULL && newNode->next == NULL) {
			printf("| Data from current node : %d, Previous node data : %d, Next node data : NULL |\n", newNode->data, newNode->previous->data);
		}
		else if (newNode->previous == NULL && newNode->next == NULL) {
			printf("| Data from current node : %d, Previous node data : NULL, Next node data : NULL |\n", newNode->data);
		}
		else {
			printf("| Data from current node : %d, Previous node data : %d, Next node data : %d |\n", newNode->data, newNode->previous->data, newNode->next->data);
			newNode = newNode->next;
		}
	}
}

int popBalloon(Dequeue* dequeue) {	
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode = dequeue->current;
	int currentNodeIndex = newNode->index;
	int currentNodeData = newNode->data;

	if (currentNodeData > 0) {
		dequeue->current = newNode->next;
	}
	else if (currentNodeData < 0) {
		dequeue->current = newNode->previous;
	}	

	newNode->next->previous = newNode->previous;
	newNode->previous->next = newNode->next;
	dequeue->size--;

	if (currentNodeData > 0) {
		for (int i = 0; i < currentNodeData - 1; i++) {
			dequeue->current = dequeue->current->next;
		}
	}
	else if (currentNodeData < 0) {
		for (int i = currentNodeData + 1; i < 0; i++) {
			dequeue->current = dequeue->current->previous;
		}		
	}		

	return currentNodeIndex;
}

int main(void) {
	Dequeue dequeue;
	int N;

	scanf("%d", &N);
	initDequeue(&dequeue);

	for (int i = 1; i < N + 1; i++) {
		int data;
		scanf("%d", &data);
		if (N == 1) {
			printf("%d", 1);
			exit(0);
		}
		if (i == N) {
			addToRear(&dequeue, data, i, 1);
		}
		else {
			addToRear(&dequeue, data, i, 0);
		}
		
	}
	
	for (int i = 0; i < N; i++) {
		printf("%d ", popBalloon(&dequeue));
	}

	return 0;
}