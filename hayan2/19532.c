#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int a, b, c, d, e, f, br = 0;

	scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);

	for (int x = -999; x <= 999; x++) {
		for (int y = -999; y <= 999; y++) {
			if ((a * x) + (b * y) == c && (d * x) + (e * y) == f) {
				printf("%d %d", x, y);
				br = 1;
				break;
			}
		}
		if (br == 1) {
			break;
		}
	}

	return 0;
}