#define _CRT_SECURE_NO_WARNINGS
#define ARRAY_LEN 9
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int arr[ARRAY_LEN];

void backtracking(int count, int len, int N, int M) {
	if (len == M) {
		for (int i = 0; i < M; i++) {
			printf("%d ", arr[i]);
		}
			
		printf("\n");
		return;
	}

	for (int i = count; i <= N; i++) {
		arr[len] = i;
		backtracking(i + 1, len + 1, N, M);
	}

	return;
}

int main() {
	int N, M;
	scanf("%d %d", &N, &M);

	backtracking(1, 0, N, M);

	return 0;
}