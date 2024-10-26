#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int hanoi(int N, int from, int to, int sub) {
	if (N == 1) {
		printf("%d %d\n", from, to);
		return;
	}

	hanoi(N - 1, from, sub, to);
	printf("%d %d\n", from, to);
	hanoi(N - 1, sub, to, from);
}

int main(void) {
	int N;

	scanf("%d", &N);

	int cnt = pow(2, N) - 1;
	printf("%d\n", cnt);

	hanoi(N, 1, 3, 2);

	return 0;
}