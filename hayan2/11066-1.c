#define _CRT_SECURE_NO_WARNINGS
#define MIN(a, b) a > b ? b : a
#define ARRAY_LEN 501
#define DEFAULT 2147483646
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int dp[ARRAY_LEN][ARRAY_LEN] = { 0, };
	int psum[ARRAY_LEN] = { 0, };
	int T, K, x;

	for (scanf("%d", &T); T--;) {
		scanf("%d", &K);

		for (int i = 1; i <= K; i++) {
			scanf("%d", &x);
			psum[i] = psum[i - 1] + x;
		}

		for (int i = 1; i <= K; i++) {
			for (int j = 1; j <= K - i; j++) {
				dp[j][i + j] = DEFAULT;

				for (int k = j; k <= i + j; k++) {
					dp[j][i + j] = MIN(dp[j][i + j], dp[j][k] + dp[k + 1][i + j] + psum[i + j] - psum[j - 1]);
				}
			}
		}
		printf("%d\n", dp[1][K]);
	}

 	return 0;
}