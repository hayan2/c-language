#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int sol(int a, int b) { // return a^b mod c
	if (b == 0) return 1;
	else if (b == 1) return a;
	else {
		ull ret = sol(a, b / 2);
		if (b & 1) return (a * ((ret * ret) % mod)) % mod;
		else return (ret * ret) % mod;
	}
}

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