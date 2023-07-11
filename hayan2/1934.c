#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// Euclidean-algorithm

int gcd(int a, int b) {
	int r;

	while (b) {
		r = a % b;
		a = b;
		b = r;
	}

	return a;
}

int main(void) {
	int t;
	int a, b;

	scanf("%d", &t);

	for (int i = 0; i < t; i++) {
		scanf("%d %d", &a, &b);

		int lowmul = gcd(a, b);

		printf("%d \n", (a * b) / lowmul);
	}

	return 0;
}