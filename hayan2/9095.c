#define _CRT_SECURE_NO_WARNINGS
#define LEN 11
#include <stdio.h>

int main(void) {
	int N, T;
	int dp[LEN] = { 0, };

	scanf("%d", &T);

	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;

	for (int i = 4; i < LEN; i++) {
		dp[i] = dp[i - 3] + dp[i - 2] + dp[i - 1];
	}

	for (int i = 0; i < T; i++) {
		scanf("%d", &N);
		printf("%d\n", dp[N]);
	}

	return 0;
}