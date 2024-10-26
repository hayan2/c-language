#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int a, b, v;

	scanf("%d %d %d", &a, &b, &v);

	printf("%d", ((v - b) % (a - b) == 0) ? ((v - b) / (a - b)) : ((v - b) / (a - b) + 1));

	return 0;
}