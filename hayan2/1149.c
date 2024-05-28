#define _CRT_SECURE_NO_WARNINGS
#define ARRAY_LEN 1001
#define RGB 3
#define RED 0
#define GREEN 1
#define BLUE 2
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	int arr[ARRAY_LEN][RGB];
	int dp[ARRAY_LEN][RGB];
	int N;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d %d %d", &arr[i][RED], &arr[i][GREEN], &arr[i][BLUE]);
		dp[i][RED] = arr[i][RED];
		dp[i][GREEN] = arr[i][GREEN];
		dp[i][BLUE] = arr[i][BLUE];
	}
	
	for (int i = 1; i < N; i++) {
		// RED
		dp[i][RED] += (arr[i][RED] + dp[i - 1][GREEN]) < (arr[i][RED] + dp[i - 1][BLUE]) ? dp[i - 1][GREEN] : dp[i - 1][BLUE];

		// GREEN
		dp[i][GREEN] += (arr[i][GREEN] + dp[i - 1][RED]) < (arr[i][GREEN] + dp[i - 1][BLUE]) ? dp[i - 1][RED] : dp[i - 1][BLUE];

		// BLUE
		dp[i][BLUE] += (arr[i][BLUE] + dp[i - 1][RED]) < (arr[i][BLUE] + dp[i - 1][GREEN]) ? dp[i - 1][RED] : dp[i - 1][GREEN];
	}

	printf("%d", (dp[N - 1][GREEN] > dp[N - 1][RED]) && (dp[N - 1][BLUE] > dp[N - 1][RED]) ? dp[N - 1][RED] : ((dp[N - 1][GREEN] > dp[N - 1][BLUE]) ? dp[N - 1][BLUE] : dp[N - 1][GREEN]));

	return 0;
}