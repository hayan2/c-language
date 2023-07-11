#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// passedddddd
typedef struct Node {
	int data;
	struct Node* parentNode;
	struct Node* leftNode;
	struct Node* rightNode;
	struct Node* queueLink;
}Node;

typedef struct Queue {
	Node* front;
	Node* rear;
	Node* currentsParentNode;
	Node* currentNode;
	Node* rootNode;
	int count;
}Queue;

void initQueue(Queue* queue) {
	queue->count = 0;
	queue->front = queue->rear = queue->currentsParentNode = NULL;
}

int isEmpty(Queue* queue) {
	return queue->count == 0;
}

Node* generatedNode(int data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->parentNode = NULL;
	newNode->leftNode = NULL;
	newNode->rightNode = NULL;
	newNode->queueLink = NULL;

	return newNode;
}

void insertNode(Queue* queue, int data) {
	Node* newNode = generatedNode(data);
	queue->currentNode = newNode;

	if (isEmpty(queue)) {
		queue->currentsParentNode = newNode;
		queue->rootNode = newNode;
		queue->front = newNode;
		queue->rear = newNode;
	}
	else {
		queue->rear->queueLink = newNode;
		queue->rear = newNode;
		
		// current's parent node is not null, next queue link
		if (queue->currentsParentNode->leftNode != NULL && queue->currentsParentNode->rightNode != NULL) {
			queue->currentsParentNode = queue->currentsParentNode->queueLink;
		}
		else {
			if (queue->currentsParentNode->leftNode == NULL) {
				newNode->parentNode = queue->currentsParentNode;
				queue->currentsParentNode->leftNode = newNode;

				printf("%d's left child node : %d | ", queue->currentsParentNode->data, queue->currentsParentNode->leftNode->data);
				printf("%d's parent node : %d\n", queue->currentNode->data, newNode->parentNode->data);
				
			}
			else if (queue->currentsParentNode->rightNode == NULL) {
				newNode->parentNode = queue->currentsParentNode;
				queue->currentsParentNode->rightNode = newNode;
				printf("%d's right child node : %d | ", queue->currentsParentNode->data, queue->currentsParentNode->rightNode->data);
				printf("%d's parent node : %d\n", queue->currentNode->data, newNode->parentNode->data);

				queue->currentsParentNode = queue->currentsParentNode->queueLink;
			}
		}
	}

	queue->count++;
}


void displayCompleteBinaryTree(Queue* queue) {	
	Node* pointer;
	pointer = queue->front;
	int linebreakCnt = 1;
	int	outputCnt = 0;

	for (int i = 0; i < queue->count; i++) {		
		printf("%d | ", pointer->data);
		pointer = pointer->queueLink;
		outputCnt++;
		
		if (linebreakCnt == outputCnt) {
			outputCnt = 0;
			linebreakCnt *= 2;
			printf("\n");
		}
	}
}

int main(void) {
	Queue queue;
	initQueue(&queue);

	insertNode(&queue, 1);
	insertNode(&queue, 2);
	insertNode(&queue, 3);
	insertNode(&queue, 4);
	insertNode(&queue, 5);
	insertNode(&queue, 6);
	insertNode(&queue, 7);
	insertNode(&queue, 8);
	insertNode(&queue, 9);
	insertNode(&queue, 10);
	insertNode(&queue, 11);
	insertNode(&queue, 12);
	insertNode(&queue, 13);
	insertNode(&queue, 14);
	insertNode(&queue, 15);
	insertNode(&queue, 16);
	insertNode(&queue, 17);
	insertNode(&queue, 18);

	displayCompleteBinaryTree(&queue);

	return 0;
}
