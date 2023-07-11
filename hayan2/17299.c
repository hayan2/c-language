#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int NGF[1000000], countArray[1000001] = { 0, };
int index = -1;

void push(int data) {
	NGF[++index] = data;
}

int isEmpty() {
	return index == -1;
}

int pop() {
	return NGF[index--];
}

int peek() {
	return NGF[index];
}

int main(void) {
	int N;

	scanf("%d", &N);

	int* arr = (int*)malloc(sizeof(int) * N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
		countArray[arr[i]]++;
	}

	for (int i = 0; i < N; i++) {
		while (!isEmpty() && countArray[arr[peek()]] < countArray[arr[i]]) {
			arr[pop()] = arr[i];
		}
		push(i);
	}

	while (!isEmpty()) {
		arr[pop()] = -1;
	}

	for (int i = 0; i < N; i++) {
		printf("%d ", arr[i]);
	}
}