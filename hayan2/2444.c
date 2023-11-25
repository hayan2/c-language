#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int n;

	scanf("%d", &n);

	for (int i = n; i > 0; i--) {
		for (int j = i - 1; j > 0; j--) {
			printf(" ");
		}

		for (int k = i; k < n; k++) {
			printf("*");
		}

		for (int l = i - 1; l < n; l++) {
			printf("*");
		}
		printf("\n");
	}

	for (int i = 0; i < n - 1; i++) {
		for (int j = i; j >= 0; j--) {
			printf(" ");
		}

		for (int k = n - 1; k > i; k--) {
			printf("*");
		}

		for (int l = n - 2; l > i; l--) {
			printf("*");
		}
		printf("\n");
	}

	return 0;
}