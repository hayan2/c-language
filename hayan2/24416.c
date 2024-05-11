#define _CRT_SECURE_NO_WARNINGS
#define ARRAY_LEN 41
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int dp[ARRAY_LEN];
int recursiveCnt = 0, dpCnt = 0;

int fibonacciRecursive(int N) {
	if (N == 1 || N == 2) {
		recursiveCnt++;
		return 1;
	}
	return fibonacciRecursive(N - 1) + fibonacciRecursive(N - 2);
}

int fibonacciDP(int N) {
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 1;

	for (int i = 3; i <= N; i++) {
		dpCnt++;
		dp[i] = dp[i - 1] + dp[i - 2];
	}
}

int main(void) {
	int N;

	scanf("%d", &N);

	fibonacciRecursive(N);
	fibonacciDP(N);

	printf("%d %d", recursiveCnt, dpCnt);

	return 0;
}