#define _CRT_SECURE_NO_WARNINGS
#define ARRAY_LEN 531442
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

char arr[ARRAY_LEN];

int cantorianSet(int N) {
	int len = pow(3, N - 1);

	if (N == 0) {
		printf("-");
		return;
	}

	cantorianSet(N - 1);
	for (int i = 0; i < len; i++) {
		printf(" ");
	}
	cantorianSet(N - 1);
}

int main(void) {
	int N;

	while (scanf("%d", &N) == 1) {
		memset(arr, '-', pow(3, N) * sizeof(char));
		cantorianSet(N);
		printf("\n");
	}	
	
	return 0;
}