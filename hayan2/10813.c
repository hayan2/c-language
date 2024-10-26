#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int arr[101];
	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 1; i < n + 1; i++) {
		arr[i] = i;
	}

	for (int i = 0; i < m; i++) {
		int a, b, temp = 0;
		scanf("%d %d", &a, &b);
		temp = arr[a];
		arr[a] = arr[b];
		arr[b] = temp;
	}

	for (int i = 1; i < n + 1; i++) {
		printf("%d ", arr[i]);
	}

	return 0;
}