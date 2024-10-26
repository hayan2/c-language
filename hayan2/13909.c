#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// closed 0 opened 1

int main(void) {
	int N;

	scanf("%d", &N);
	int res = 1;

	for (int i = 2; i * i < N + 1; i++) {
		res++;
	}

	printf("%d", res);

	return 0;
}