#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	long long int n;

	scanf("%lld", &n);

	printf("%lld\n3", ((n - 1) * (n - 2) * n) / 6);

	return 0;
}