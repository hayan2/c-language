#define _CRT_SECURE_NO_WARNINGS
#define MAX_LEN 101
#define ROOT 1
#include <stdio.h>
#include <stdlib.h>

typedef struct Array {
	int* arr;
	int size;
}Array;

int visited[MAX_LEN] = { 0, };
int res = -1;

int compare(const void* a, const void* b) {
	return (*(int*)a - *(int*)b);
}

Array* generateArray(int N) {
	return (Array*)malloc(sizeof(Array) * N);
}

void initArray(Array* arr, int N) {
	for (int i = 1; i <= N; i++) {
		arr[i].arr = (int*)malloc(sizeof(int) * MAX_LEN);
		arr[i].size = 0;
	}
}

void DFS(Array* arr, int r) {
	if (visited[r] == 1) {
		return;
	}

	visited[r] = 1;
	res++;

	for (int i = 0; i < arr[r].size; i++) {
		DFS(arr, arr[r].arr[i]);
	}
}

int main(void) {
	int N, M, u, v;
	
	scanf("%d", &N);
	scanf("%d", &M);

	Array* arr = generateArray(N);
	initArray(arr, N);

	for (int i = 0; i < M; i++) {
		scanf("%d %d", &u, &v);
		
		arr[u].arr[arr[u].size++] = v;
		arr[v].arr[arr[v].size++] = u;
	}

	for (int i = 1; i <= N; i++) {
		qsort(arr[i].arr, arr[i].size, sizeof(int), compare);
	}

	DFS(arr, ROOT);

	printf("%d", res);

	return 0;
}