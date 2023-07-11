#define _CRT_SECURE_NO_WARNINGS
#define MOD 1000000007
#include <stdio.h>

long long getResult(long long base, int power) {
	long long result = 1;
	
	while (power) {
		if (power % 2) {
			result = (result * base) % MOD;
		}
		base = (base * base) % MOD;
		power /= 2;
	}
	
	return result;
}

int main(void) {
	long long N;
	int T;

	scanf("%d", &T);

	for (int i = 0; i < T; i++) {
		scanf("%lld", &N);

		if (N < 3) {
			printf("1\n");
		}
		else {
			printf("%lld\n", getResult(2, N - 2));
		}
	}

	return 0;
}