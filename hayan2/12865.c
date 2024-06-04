#define _CRT_SECURE_NO_WARNINGS
#define MAX(a, b) a > b ? a : b
#define ARRAY_LEN 101
#define TWO 2
#define ARRAY_WEIGHT 0
#define ARRAY_VALUE 1
#define WEIGHT 100001
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int arr[ARRAY_LEN][TWO];
int dp[ARRAY_LEN][WEIGHT] = { 0, };

int main(void) {
	int N, K;

	scanf("%d %d", &N, &K);

	for (int i = 1; i <= N; i++) {
		scanf("%d %d", &arr[i][ARRAY_WEIGHT], &arr[i][ARRAY_VALUE]);
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= K; j++) {
			if (arr[i][ARRAY_WEIGHT] <= j) {
				if (dp[i - 1][j] < arr[i][ARRAY_VALUE] + dp[i - 1][j - arr[i][ARRAY_WEIGHT]]) {
					dp[i][j] = arr[i][ARRAY_VALUE] + dp[i - 1][j - arr[i][ARRAY_WEIGHT]];
				}
				else {
					dp[i][j] = dp[i - 1][j];
				}				
			}
			else {
				dp[i][j] = dp[i - 1][j];
			}
		}
	}

	printf("%d", dp[N][K]);

	return 0;
}