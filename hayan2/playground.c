#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node* link;
}Node;

typedef struct Stack {
	Node* top;
	int count;
}Stack;

Node* generatedNode(int data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	
}

void initStack(Stack* stack) {
	stack->top = NULL;
	stack->count = 0;
}

void push(Stack* stack, int data) {
	Node* newNode = (Node)malloc()
}

/*

Node* generatedNode(int data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->parentNode = NULL;
	newNode->leftNode = NULL;
	newNode->rightNode = NULL;
	newNode->queueLink = NULL;

	return newNode;
}
*/

int pop(Stack* stack) {

}

int peek(Stack* stack) {

}

int main(void) {
	Stack stack;
	
	initStack(&stack);



	return 0;
}