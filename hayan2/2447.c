#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void getResult(int N, int row, int col) {
	if ((row / N) % 3 == 1 && (col / N) % 3 == 1) {
		printf(" ");
	}
	else {
		if ((N / 3) == 0) {
			printf("*");
		}
		else {
			getResult(N / 3, row, col);
		}
	}
}

int main(void) {
	int N;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			getResult(N, j, i);			
		}
		printf("\n");
	}

	return 0;
}