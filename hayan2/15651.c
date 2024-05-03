#define _CRT_SECURE_NO_WARNINGS
#define ARRAY_LEN
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int arr[9];

void backtracking(int len, int N, int M) {
	if (len == M) {
		for (int i = 0; i < M; i++) {
			printf("%d ", arr[i]);
		}
		printf("\n");
		return;
	}

	for (int i = 1; i <= N; i++) {
		arr[len] = i;
		backtracking(len + 1, N, M);
	}
}

int main(void) {
	int N, M;

	scanf("%d %d", &N, &M);

	backtracking(0, N, M);

	return 0;
}