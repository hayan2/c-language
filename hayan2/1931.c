#define _CRT_SECURE_NO_WARNINGS
#define MAX(a, b) a > b ? a : b
#define MIN(a, b) a > b ? b : a
#define START 0
#define END 1
#include <stdio.h>
#include <stdlib.h>

int compare(const void* pa, const void* pb) {
	const int* a = *(const int**)pa;
	const int* b = *(const int**)pb;
	if (a[0] == b[0])
		return a[1] - b[1];
	else
		return a[0] - b[0];
}

int main(void) {
	int** arr;	
	int N, res = 0;

	scanf("%d", &N);

	arr = malloc(N * sizeof(int*));	
	
	for (int i = 0; i < N; i++) {		
		arr[i] = malloc(2 * sizeof(int));
		scanf("%d %d", &arr[i][START], &arr[i][END]);
	}

	qsort(arr, N, sizeof arr[START], compare);
	
	int t = arr[0][END];

	// O(N)?
	for (int i = 1; i < N; i++) {		
		if (arr[i][START] < t) {
			t = MIN(t, arr[i][END]);
		}
		else {
			t = arr[i][END];
			res++;
		}
	}

	printf("%d", res + 1);

	free(arr);	

	return 0;
}