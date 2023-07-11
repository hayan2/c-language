#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	if (6 & (1 << 2)) {
		printf("yes");
	}
	else {
		printf("no");
	}

	return 0;
}