#define _CRT_SECURE_NO_WARNINGS
#define ARRAY_LEN 9
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int arr[ARRAY_LEN];

void DFS(int x, int len, int N, int M) {
	if (len == M) {
		for (int i = 0; i < M; i++) {
			printf("%d ", arr[i]);
		}
		printf("\n");
		return;
	}

	for (int i = x; i <= N; i++) {
		arr[len] = i;
		DFS(i + 1, len + 1, N, M);
	}
}

int main(void) {
	int N, M;

	scanf("%d %d", &N, &M);

	DFS(1, 0, N, M);

	return 0;
}