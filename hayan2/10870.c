#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int fibonacci(int N) {
	if (N == 0) {
		return 0;
	}
	if (N == 1) {
		return 1;
	}

	return fibonacci(N - 1) + fibonacci(N - 2);
}

int main(void) {
	int N;

	scanf("%d", &N);

	printf("%d", fibonacci(N));

	return 0;
}