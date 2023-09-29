#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int h, m, c;

	scanf("%d %d %d", &h, &m, &c);

	h *= 60;
	h += m;
	h += c;
	if (h >= 1440) {
		h -= 1440;
	}
	m = h % 60;
	h /= 60;

	printf("%d %d", h, m);

	return 0;
}