#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
	int x1, x2, x3, y1, y2, y3;

	scanf("%d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3);

	int result = (x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1);

	if (result > 0) {
		printf("1");
	}
	else if (result < 0) {
		printf("-1");
	}
	else {
		printf("0");
	}

	return 0;
}