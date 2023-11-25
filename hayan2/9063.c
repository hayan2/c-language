#define _CRT_SECURE_NO_WARNINGS
#define MAX(a, b) a > b ? a : b
#define MIN(a, b) a < b ? a : b
#include <stdio.h>

int main(void) {
	int n, x, y, xMin = 10001, yMin = 10001, xMax = -10001, yMax = -10001;

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d %d", &x, &y);
		xMin = MIN(xMin, x);
		yMin = MIN(yMin, y);
		xMax = MAX(xMax, x);
		yMax = MAX(yMax, y);
	}

	printf("%d", (xMax - xMin) * (yMax - yMin));

	return 0;
}