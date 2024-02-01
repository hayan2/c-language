#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node* next;
	struct Node* previous;
}Node;

typedef struct Dequeue {
	Node* front;
	Node* rear;
	int size;
}Dequeue;

void initDequeue(Dequeue* dequeue) {
	dequeue->front = NULL;
	dequeue->rear = NULL;
	dequeue->size = 0;
}

int isDequeueEmpty(Dequeue* dequeue) {
	return dequeue->size == 0;
}

void addToFront(Dequeue* dequeue, int data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL;
	newNode->previous = NULL;

	if (isDequeueEmpty(dequeue)) {
		dequeue->front = newNode;
		dequeue->rear = newNode;
	}
	else {
		newNode->next = dequeue->front;
		dequeue->front->previous = newNode;
		dequeue->front = newNode;
	}
	dequeue->size++;
}

void addToRear(Dequeue* dequeue, int data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
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
	}
	dequeue->size++;

}

int removeFromFront(Dequeue* dequeue) {
	if (isDequeueEmpty(dequeue)) {
		return -1;
	}

	int returnData;
	returnData = dequeue->front->data;

	dequeue->front = dequeue->front->next;
	dequeue->size--;

	return returnData;
}

int removeFromRear(Dequeue* dequeue) {
	if (isDequeueEmpty(dequeue)) {
		return -1;
	}

	int returnData;
	returnData = dequeue->rear->data;

	dequeue->rear = dequeue->rear->previous;
	dequeue->size--;

	return returnData;
}

int displayFrontData(Dequeue* dequeue) {
	if (isDequeueEmpty(dequeue)) {
		return -1;
	}
	else {
		return dequeue->front->data;
	}
}

int displayRearData(Dequeue* dequeue) {
	if (isDequeueEmpty(dequeue)) {
		return -1;
	}
	else {
		return dequeue->rear->data;
	}
}

int displayDequeue(Dequeue* dequeue) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode = dequeue->front;

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

int main(void) {
	Dequeue dequeue;
	int N;

	scanf("%d", &N);
	initDequeue(&dequeue);	

	for (int i = 0; i < N; i++) {
		int command, x;		
		scanf("%d", &command);		
		switch (command) {			
		case 1:
			scanf("%d", &x);
			addToFront(&dequeue, x);
			break;
		case 2:
			scanf("%d", &x);
			addToRear(&dequeue, x);
			break;
		case 3:
			printf("%d\n", removeFromFront(&dequeue));
			break;
		case 4:
			printf("%d\n", removeFromRear(&dequeue));
			break;
		case 5:
			printf("%d\n", dequeue.size);
			break;
		case 6:
			printf("%d\n", isDequeueEmpty(&dequeue));
			break;
		case 7:
			printf("%d\n", displayFrontData(&dequeue));
			break;
		case 8:
			printf("%d\n", displayRearData(&dequeue));
			break;
		}
		// displayDequeue(&dequeue);
	}

	return 0;
}