#define _CRT_SECURE_NO_WARNINGS
#define ARRAY_LEN 501
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int arr[ARRAY_LEN][ARRAY_LEN];
int dp[ARRAY_LEN][ARRAY_LEN];

int main(void) {		
	int result = 0;
	int N;

	scanf("%d", &N);
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < i + 1; j++) {
			scanf("%d", &arr[i][j]);
			dp[i][j] = arr[i][j];
		}
	}
	
	if (N == 1) {
		printf("%d", arr[0][0]);
		exit(0);
	}

	for (int i = 1; i < N; i++) {
		for (int j = 0; j < i + 1; j++) {
			if (j != 0) {
				dp[i][j] = (dp[i - 1][j - 1] + arr[i][j]) < (dp[i - 1][j] + arr[i][j]) ? (dp[i - 1][j] + arr[i][j]) : (dp[i - 1][j - 1] + arr[i][j]);
			}
			else {
				dp[i][j] = dp[i - 1][j] + arr[i][j];
			}
		}
	}
	
	for (int i = 1; i < N; i++) {
		result = (result < dp[N - 1][i]) ? dp[N - 1][i] : result;
	}

	printf("%d", result);

	return 0;
}