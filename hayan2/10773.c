#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node* link;
}Node;

typedef struct Stack {
	Node* top;
	int size;
	int result;
}Stack;

void initNode(Node* node) {
	node->data = 0;
	node->link = NULL;
}

void initStack(Stack* stack) {
	stack->top = NULL;
	stack->size = 0;
	stack->result = 0;
}

int isStackEmpty(Stack* stack) {
	return stack->size == 0;
}

void push(Stack* stack, int data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	initNode(newNode);
	newNode->data = data;

	stack->result += newNode->data;

	if (isStackEmpty(stack)) {
		stack->top = newNode;
		stack->size++;
		return;
	}

	newNode->link = stack->top;
	stack->top = newNode;
	stack->size++;

	return;
}

void pop(Stack* stack) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	initNode(newNode);
	newNode = stack->top;

	stack->result -= newNode->data;
	stack->top = newNode->link;
	stack->size--;

	return;
}

int getResult(Stack* stack) {
	return stack->result;
}

int main(void) {	
	Stack stack;
	int N, x;

	initStack(&stack);

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &x);

		if (x == 0) {
			pop(&stack);
		}
		else {
			push(&stack, x);
		}
	}

	printf("%d", getResult(&stack));

	return 0;
}