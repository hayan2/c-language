#define _CRT_SECURE_NO_WARNINGS
#define ARRAY_SIZE 1000001
#include <stdio.h>

int primeNumber[ARRAY_SIZE];

int main(void) {
	int T;

	scanf("%d", &T);

	primeNumber[1] = 0;
	for (int i = 2; i < ARRAY_SIZE; i++) {
		primeNumber[i] = i;
	}

	for (int i = 2; i <= ARRAY_SIZE; i++) {
		if (primeNumber[i] == 0) {
			continue;
		}

		for (int j = 2 * i; j <= ARRAY_SIZE; j += i) {
			primeNumber[j] = 0;
		}
	}

	for (int t = 0; t < T; t++) {
		int res = 0;
		int N;

		scanf("%d", &N);

		for (int i = 2; i <= N / 2; i++) {
			if (primeNumber[i] + primeNumber[N - i] == N) {
				res++;
			}
		}
		printf("%d\n", res);
	}

	return 0;
}