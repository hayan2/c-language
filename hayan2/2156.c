#define _CRT_SECURE_NO_WARNINGS
#define MAX(a, b) a > b ? a : b
#define ARRAY_LEN 10001
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	int arr[ARRAY_LEN] = { 0, };
	int dp[ARRAY_LEN] = { 0, };
	int N, result = 0, flag = 0;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
		dp[i] = arr[i];	
	}

	if (N == 1) {
		printf("%d", arr[0]);
		exit(0);
	}

	dp[1] += arr[0];	
	dp[2] += MAX(arr[0], arr[1]);
	dp[3] += MAX(arr[2] + dp[0], dp[1]);

	if (N < 4) {
		result = MAX(dp[0], dp[1]);
		result = MAX(result, dp[2]);
		result = MAX(result, dp[3]);
	}
	
	for (int i = 4; i <= N; i++) {
		dp[i] += dp[i - 2];
		dp[i] = MAX(arr[i] + arr[i - 1] + dp[i - 3], dp[i]);
		dp[i] = MAX(arr[i] + arr[i - 1] + dp[i - 4], dp[i]);
		dp[i] = MAX(arr[i] + dp[i - 3], dp[i]);

		result = MAX(dp[i], result);
	}

	printf("%d", result);

	return 0;
}