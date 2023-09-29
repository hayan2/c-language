#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int h, m;

	scanf("%d %d", &h, &m);

	h *= 60;
	h += m;
	if (h - 45 < 0) {
		h -= 45;
		h += 1440;
	}
	else {
		h -= 45;
	}
	m = h % 60;
	h /= 60;

	printf("%d %d", h, m);

	return 0;
}