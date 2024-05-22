#define _CRT_SECURE_NO_WARNINGS
#define MAX_DEFAULT -1001
#define ARRAY_LEN 100001
#include <stdio.h>

int arr[ARRAY_LEN];
int dp[ARRAY_LEN];

int main(void) {
	int N;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
		dp[i] = arr[i];
	}

	int max = arr[0];

	for (int i = 1; i < N; i++) {
		if (dp[i - 1] + arr[i] + arr[i + 1] > arr[i] + arr[i + 1]) {
			dp[i] += dp[i - 1];
		}		
		max = (max > arr[i]) ? max : arr[i];
		max = (max > dp[i]) ? max : dp[i];
	}

	printf("%d", max);

	return 0;
}