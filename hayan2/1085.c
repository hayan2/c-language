#define _CRT_SECURE_NO_WARNINGS
#define MIN(a, b) a < b ? a : b
#include <stdio.h>

int main(void) {
	// x, y, w, h, 0, 0
	// w - x, h - y, x, y

	int x, y, w, h, min = 1001;

	scanf("%d %d %d %d", &x, &y, &w, &h);

	min = MIN(min, x);
	min = MIN(min, y);
	min = MIN(min, w - x);
	min = MIN(min, h - y);

	printf("%d", min);

	return 0;
}