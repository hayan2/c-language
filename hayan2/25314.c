#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int n;

	scanf("%d", &n);
	n /= 4;

	for (int i = 0; i < n; i++) {
		printf("long ");
	}

	printf("int");
	

	return 0;
}