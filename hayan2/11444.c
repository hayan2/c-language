#define _CRT_SECURE_NO_WARNINGS
#define MOD 1000000007
#define ARRAY_LEN 2
#include <stdio.h>

typedef unsigned long long ull;

void getResult(ull res[][ARRAY_LEN], ull matrix[][ARRAY_LEN]);

int main(void) {
	ull matrix[ARRAY_LEN][ARRAY_LEN] = { {1, 1}, {1, 0} }, res[ARRAY_LEN][ARRAY_LEN] = { {1, 0}, {0, 1} };
	ull n;

	scanf("%lld", &n);
	
	while (n) {
		if (n & 1) {
			getResult(res, matrix);
		}
		getResult(matrix, matrix);
		n >>= 1;
	}

	printf("%lld", res[0][1] % MOD);

	return 0;
}

void getResult(ull res[][ARRAY_LEN], ull matrix[][ARRAY_LEN]) {
	ull tmp[ARRAY_LEN][ARRAY_LEN] = { 0, };

	for (int i = 0; i < ARRAY_LEN; i++) {
		for (int j = 0; j < ARRAY_LEN; j++) {
			for (int k = 0; k < ARRAY_LEN; k++) {
				tmp[i][j] += (res[i][k] * matrix[k][j]) % MOD;
			}
		}
	}

	for (int i = 0; i < ARRAY_LEN; i++) {
		for (int j = 0; j < ARRAY_LEN; j++) {
			res[i][j] = tmp[i][j] % MOD;
		}
	}
}