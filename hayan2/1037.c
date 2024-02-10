#define _CRT_SECURE_NO_WARNINGS
#define ARRAY_SIZE 51
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void* a, const void* b) {
	return *((int*)a) - *((int*)b);
}

int main(void) {
	int arr[ARRAY_SIZE];
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}
	
	qsort(arr, N, sizeof(int), compare);

	printf("%d", arr[0] * arr[N - 1]);

	return 0;
}