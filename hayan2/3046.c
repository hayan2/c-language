#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int r1, S;

	scanf("%d %d", &r1, &S);

	printf("%d", (S * 2) - r1);

	return 0;
}