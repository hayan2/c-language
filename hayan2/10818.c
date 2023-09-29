#define _CRT_SECURE_NO_WARNINGS
#define MAX(a, b) (a > b) ? a : b
#define MIN(a, b) (a < b) ? a : b
#include <stdio.h>

int main(void) {
	int max = -1000001, min = 1000001;
	int n, a;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &a);
		max = MAX(max, a);
		min = MIN(min, a);
	}

	printf("%d %d", min, max);

	return 0;
}