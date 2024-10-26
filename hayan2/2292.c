#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int n, idx = 1, check = 1;

	scanf("%d", &n);

	while (check < n) {
		check += (6 * idx++);
	}

	printf("%d", idx);

	return 0;
}