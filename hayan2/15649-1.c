#define _CRT_SECURE_NO_WARNINGS
#define ARRAY_LEN 9
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int arr[ARRAY_LEN];
int visited[ARRAY_LEN];

void DFS(int len, int N, int M) {
	if (len == M) {
		for (int i = 0; i < M; i++) {
			printf("%d ", arr[i]);
		}
		printf("\n");
		return;
	}

	for (int i = 1; i <= N; i++) {
		if (visited[i] == 0) {
			arr[len] = i;
			visited[i] = 1;
			DFS(len + 1, N, M);
			visited[i] = 0;
		}
		
	}
}


int main(void) {
	int N, M;

	scanf("%d %d", &N, &M);

	DFS(0, N, M);

	return 0;
}