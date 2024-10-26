#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int n, result = 0;

	scanf("%d", &n);

	for (int i = 1; i < n + 1; i++) {
		result += i;
	}

	printf("%d", result);

	return 0;
}