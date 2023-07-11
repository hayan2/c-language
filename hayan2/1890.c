#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

long long board[101][101] = { 0, };
long long dp[101][101] = { 0, };

// dynamic programming
// recurrence relation - board[N - 1][N - 1]

int main(void) {
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &board[i][j]);
		}
	}

	dp[0][0] = 1;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int leap = board[i][j];

			if (i != (N - 1) && (i + leap) < N) {
				dp[i + leap][j] += dp[i][j];
			}
			if (j != (N - 1) && (j + leap) < N) {
				dp[i][j + leap] += dp[i][j];
			}
		}
	}
	
	printf("%lld", dp[N - 1][N- 1]);

	return 0;
}