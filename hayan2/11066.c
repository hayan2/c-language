#define _CRT_SECURE_NO_WARNINGS
#define MIN(a, b) a > b ? b : a
#define DEFAULT 2147483641
#define ARRAY_LEN 501
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int dp[ARRAY_LEN][ARRAY_LEN];
	int arr[ARRAY_LEN], cost[ARRAY_LEN];
	int N;
	
	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		scanf("%d", &arr[i]);
		dp[i][i] = arr[i];
	}

	// dp[i][j] = MIN(dp[i][j], dp[i][k] + dp[k + 1][j])
	for (int i = 1; i < N; i++) {
		for (int j = i + 1; j <= N; j++) {
			dp[i][j] = DEFAULT;

			for (int k = i; k <= j; k++) {

			}
		}
	}

	return 0;
}