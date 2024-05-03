#define _CRT_SECURE_NO_WARNINGS
#define ARRAY_LEN 9
#include <stdio.h>

int arr[ARRAY_LEN];
int visited[ARRAY_LEN] = { 0, };

void backtracking(int count, int N, int M) {
	if (count == M) {
		for (int i = 0; i < M; i++) {
			printf("%d ", arr[i]);
		}
		printf("\n");
		return;
	}
	
	for (int i = 1; i <= N; i++) {
		if (visited[i] == 0) {
			arr[count] = i;
			visited[i] = 1;
			backtracking(count + 1, N, M);
			visited[i] = 0;
		}
	}
}

int main(void) {
	int N, M;

	scanf("%d %d", &N, &M);
	
	backtracking(0, N, M);

	return 0;
}