#define _CRT_SECURE_NO_WARNINGS
#define STR_LEN 1000001
#define BOMB_LEN 37
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char str[STR_LEN];
char bomb[BOMB_LEN];

typedef struct Stack {
	char str[STR_LEN];
	int top;
}Stack;

Stack* generateStack() {
	return (Stack*)malloc(sizeof(Stack));
}

void initStack(Stack* stack) {
	memset(stack->str, '\0', STR_LEN - 1);
	stack->top = 0;
}

int isEmpty(Stack* stack) {
	return stack->top == 0;
}

void push(Stack* stack, char s) {
	stack->str[stack->top++] = s;
}

void pop(Stack* stack, int bombLen) {
	stack->top -= bombLen;	
}

int sol(Stack* stack, int strIdx, int bombLen) {
	int bombIdx = 0;
	for (int i = strIdx; i < (strIdx + bombLen); i++) {
		if (stack->str[i] != bomb[bombIdx++]) {
			return 0;
		}
	}

	return 1;
}

void display(Stack* stack) {
	for (int i = 0; i < stack->top; i++) {
		printf("%c", stack->str[i]);
	}
}

int main(void) {
	Stack* stack = generateStack();
	initStack(stack);
	
	// display(stack);

	scanf("%s", str);
	scanf("%s", bomb);

	int strLen = strlen(str);
	int bombLen = strlen(bomb);

	for (int i = 0; i < strLen; i++) {
		push(stack, str[i]);

		if (stack->str[stack->top - 1] == bomb[bombLen - 1] && stack->top >= bombLen) {
			if (sol(stack, (stack->top - bombLen), bombLen)) {
				pop(stack, bombLen);
			}
		}
	}

	isEmpty(stack) ? printf("FRULA") : display(stack);

	return 0;
}