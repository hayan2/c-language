#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int my_pow(int base, int exp);

int main(void) {
	int n;

	scanf("%d", &n);

	// formula - (2^n * 2^n + 1) + (2^n * 2)
	printf("%d", (my_pow(2, n) * my_pow(2, n) + 1) + (my_pow(2, n) * 2));

	return 0;
}

int my_pow(int base, int exp) {
	int res = 1;
	while (exp) {
		if (exp & 1) {
			res *= base;
		}
		exp >>= 1;
		base *= base;
	}

	return res;
}