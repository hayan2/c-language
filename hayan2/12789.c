#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node	{
	int num;
	struct Node* link;
}Node;

typedef struct Stack {
	Node* top;
	int count;
}Stack;

int isStackEmpty(Stack* stack) {
	return stack->count == 0;	
}

void initNode(Node* node, int data) {	
	node->num = data;
	node->link = NULL;
}

void initStack(Stack* stack) {
	stack->top = NULL;
	stack->count = 0;
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

int main(void) {
	int N;
	Stack stack;

	scanf("%d", &N);

	initStack(&stack);

	for (int i = 0; i < N; i++) {
		int data;
		scanf("%d", &data);
		push(&stack, data);
	}

	displayStack(&stack);

	return 0;
}