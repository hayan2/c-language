#define _CRT_SECURE_NO_WARNINGS
#define MOD 1000000007
#include <stdio.h>

typedef unsigned long long ull;

ull factorial(int S, int N) {
	ull ret = 1;

	for (int i = S; i <= N; i++)
		ret = ret * i % MOD;

	return ret;
}

ull pow(int a, int b) {
	if (b == 0)
		return 1;

	if (b == 1)
		return a % MOD;

	ull ret = pow(a, b / 2);

	return (b & 1) ? (a * ((ret * ret) % MOD)) % MOD : (ret * ret) % MOD;
}

int main(void) {
	int N, K;

	scanf("%d %d", &N, &K);

	printf("%lld", factorial(N - K + 1, N) * pow(factorial(1, K), MOD - 2) % MOD);

	return 0;
}