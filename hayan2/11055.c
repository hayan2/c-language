#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int bigger(int a, int b) {
	if (a > b) {
		return a;
	}

	return b;
}

int main(void) {
	int arr[1001] = { 0, };
	int dp[1001];
	int N;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
		dp[i] = arr[i];
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < i + 1; j++) {
			if ((arr[j] < arr[i]) && (dp[i] < dp[j] + arr[i])) {
				dp[i] = dp[j] + arr[i];
			}
		}
	}

	int result = 0;
	for (int i = 0; i < N; i++) {
		result = bigger(result, dp[i]);
	}

	printf("%d", result);

	return 0;
}