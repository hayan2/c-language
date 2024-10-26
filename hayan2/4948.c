#define _CRT_SECURE_NO_WARNINGS
#define ARRAY_SIZE 246917
#include <stdio.h>

int primeNumber[ARRAY_SIZE];

int main(void) {
	int N;

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

	while (1) {
		int res = 0;

		scanf("%d", &N);

		if (N == 0) {
			break;
		}

		for (int i = N + 1; i <= N * 2; i++) {
			if (primeNumber[i] != 0) {
				res++;
			}
		}
		printf("%d\n", res);
	}

	return 0;
}