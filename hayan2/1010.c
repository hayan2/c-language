#define _CRT_SECURE_NO_WARNINGS
#define ARRAY_SIZE 31
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	static int arr[ARRAY_SIZE][ARRAY_SIZE];
	int T;

	scanf("%d", &T);

	for (int i = 1; i < ARRAY_SIZE; i++) {
		for (int j = 1; j < ARRAY_SIZE; j++) {
			if (i == j) {
				arr[i][j] = 1;
			}
			else if (i == 1 || j == 1) {
				arr[i][j] = (i > j) ? i : j;
			}
			else {
				arr[i][j] = arr[i][j - 1] + arr[i - 1][j - 1];
			}
		}
	}

	for (int i = 0; i < T; i++) {
		int N, M;
		scanf("%d %d", &N, &M);
		printf("%d\n", arr[N][M]);
	}

	return 0;
}