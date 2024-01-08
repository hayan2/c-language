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
}Stack;

void initNode(Node* node) {
	node->data = 0;
	node->link = NULL;
}
void initStack(Stack* stack) {
	stack->size = 0;
	stack->top = NULL;
}
void push(Stack* stack, int data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	initNode(newNode);

	newNode->data = data;

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
int pop(Stack* stack) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (isStackEmpty(stack)) {
		return -1;
	}

	newNode = stack->top;
	stack->top = newNode->link;
	stack->size--;
	
	return newNode->data;
}
int peek(Stack* stack) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (isStackEmpty(stack)) {
		return -1;
	}	

	return stack->top->data;
}
int displayStackSize(Stack* stack) {
	return stack->size;
}

int isStackEmpty(Stack* stack) {
	return stack->size == 0;
}

int main(void) {
	Stack stack;
	int N;

	initStack(&stack);
		
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		int command, x, data;

		scanf("%d", &command);

		switch (command) {
		case 1:
			scanf("%d", &x);
			push(&stack, x);
			break;
		case 2:	
			data = pop(&stack);			
			printf("%d\n", data);
			break;
		case 3:
			printf("%d\n", displayStackSize(&stack));
			break;
		case 4:
			printf("%d\n", isStackEmpty(&stack));
			break;
		case 5:
			printf("%d\n", peek(&stack));
			break;
		}
	}

	return 0;
}
