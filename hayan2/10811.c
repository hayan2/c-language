#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int arr[101];
	int n, m;

	scanf("%d %d", &n ,&m);

	for (int i = 1; i < n + 1; i++) {
		arr[i] = i;
	}

	for (int i = 0; i < m; i++) {
		int k, l;

		scanf("%d %d", &k, &l);

		while (k < l) {
			int temp = arr[l];
			arr[l--] = arr[k];
			arr[k++] = temp;
		}
	}

	for (int i = 1; i < n + 1; i++) {
		printf("%d ", arr[i]);
	}

	return 0;
}