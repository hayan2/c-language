#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

long long int gcd(long long int a, long long int b);

int main(void) {
	long long int A, B;

	scanf("%lld %lld", &A, &B);

	long long int res = (A >= B) ? gcd(A, B) : gcd(B, A);
	printf("%lld", A * B / res);

	return 0;
}

long long int gcd(long long int a, long long int b) {
	long long int MOD;
	while (b) {
		MOD = a % b;
		a = b;
		b = MOD;
	}

	return a;
}