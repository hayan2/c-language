#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	long long A, B, C;

	scanf("%lld %lld %lld", &A, &B, &C);

	long long res = 1;

	while (B > 0) {
		if (B % 2 == 1) {
			res = (res * A) % C;
		}
		A = ((A % C) * (A % C)) % C;
		B /= 2;
	}

	printf("%lld", res);

	return 0;
}