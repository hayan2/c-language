#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	int B = 100000;
	while (B) {
		printf("%d\n", B);
		B >>= 1;
	}

	return 0;
}