#define _CRT_SECURE_NO_WARNINGS
#define MAX(a, b) a > b ? a : b
#include <stdio.h>

int main(void) {
	int arr[101];
	int n, m, max = -1;

	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	for (int i = 0; i < n - 2; i++) {
		for (int j = i + 1; j < n - 1; j++) {
			for (int k = j + 1; k < n; k++) {
				if ((arr[i] + arr[j] + arr[k]) <= m) {
					max = MAX(max, arr[i] + arr[j] + arr[k]);
				}
			}
		}
	}

	printf("%d", max);

	return 0;
}