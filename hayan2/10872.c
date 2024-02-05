#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int factorial(int N) {
	if (N == 0) {
		return 1;
	}

	return N * factorial(N - 1);
}

int main(void) {
	int N;

	scanf("%d", &N);

	printf("%d", factorial(N));

	return 0;
}