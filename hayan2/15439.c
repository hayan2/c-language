#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	int N;

	scanf("%d", &N);

	printf("%d", N * (N - 1));

	return 0;
}