#define _CRT_SECURE_NO_WARNINGS
#define MIN(a, b) a > b ? b : a
#define uint unsigned int
#define DEFAULT 2147483641
#define ARRAY_LEN 501
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int dp[ARRAY_LEN][ARRAY_LEN] = { 0, };
	int psum[ARRAY_LEN] = { 0, };
	int N, x, T;
	
	for (scanf("%d", &T); T--;) {
		scanf("%d", &N);

		for (int i = 1; i <= N; i++) {
			scanf("%d", &x);
			psum[i] = psum[i - 1] + x;
		}

		// dp[i][j] = MIN(dp[i][j], dp[i][k] + dp[k + 1][j]) ?
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N - i; j++) {
				dp[j][i + j] = DEFAULT;

				for (int k = j; k <= j + i; k++) {
					dp[j][i + j] = MIN(dp[j][i + j], dp[j][k] + dp[k + 1][i + j] + psum[i + j] - psum[j - 1]);
				}
			}
		}
		printf("%d\n", dp[1][N]);
	}

	

	return 0;
}