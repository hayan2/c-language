#define _CRT_SECURE_NO_WARNINGS
#define MOD 1000000000
#define ARRAY_LEN 101
#define DIGIT 10
#include <stdio.h>

int main(void) {
	long long dp[ARRAY_LEN][DIGIT];
	long long result = 0;
	int N;

	scanf("%d", &N);

	if (N == 1) {
		printf("9");
		exit(0);
	}

	dp[1][0] = 0;
	for (int i = 1; i < DIGIT; i++) {
		dp[1][i] = 1;
	}
	
	for (int i = 2; i <= N; i++) {
		for (int digit = 0; digit < DIGIT; digit++) {			
			if (digit == 0) {
				dp[i][digit] = dp[i - 1][digit + 1] % MOD;
			}

			else if (digit == 9) {
				dp[i][digit] = dp[i - 1][digit - 1] % MOD;
			}
			else {
				dp[i][digit] = ((dp[i - 1][digit - 1] % MOD) + (dp[i - 1][digit + 1] % MOD)) % MOD;
			}

			if (i == N) {
				result += dp[i][digit] % MOD;
			}			
		}
	}

	printf("%lld", result % MOD);

	return 0;
}