#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int N, M;

	scanf("%d %d", &N, &M);

	printf("%d", (N * M) - 1);

	return 0;
}