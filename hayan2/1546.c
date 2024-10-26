#define _CRT_SECURE_NO_WARNINGS
#define MAX(a, b) (a > b) ? a : b
#include <stdio.h>

int main(void) {
	float arr[1001];
	int n, len = 0;
	float average = 0, max = 0;

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		max = MAX(max, arr[i]);
	}

	for (int i = 0; i < n; i++) {
		average += (arr[i] / max * 100);
		len++;
	}

	printf("%lf", average / len);

	return 0;
}