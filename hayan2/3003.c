#define _CRT_SECURE_NO_WARNINGS
#define LEN 6
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int chess[LEN] = { 1, 1, 2, 2, 2, 8 };
	int arr[LEN];

	for (int i = 0; i < LEN; i++) {
		scanf("%d", &arr[i]);

		arr[i] = chess[i] - arr[i];
	}

	for (int i = 0; i < LEN; i++) {
		printf("%d ", arr[i]);
	}

	return 0;
}