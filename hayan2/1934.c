#define _CRT_SECURE_NO_WARNINGS
#define MAX_SIZE 45001
#include <stdio.h>

int gcd(int a, int b);

int main(void) {
	int N;
	int A, B;

	scanf("%d", &N);

	for (int j = 0; j < N; j++) {
		scanf("%d %d", &A, &B);
		int res = (A >= B) ? gcd(A, B) : gcd(B, A);
		printf("%d\n", (A * B) / res);
	}

	return 0;
}

int gcd(int a, int b) {
	int MOD;
	while (b) {
		MOD = a % b;
		a = b;
		b = MOD;
	}

	return a;
}