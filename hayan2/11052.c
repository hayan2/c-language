#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int bigger(int a, int b) {
	if (a > b) {
		return a;
	}
	return b;
}

int main(void) {
	int cards[1001] = { 0, };
	int dp[1001] = { 0, };
	int N;

	scanf("%d", &N);

	for (int i = 1; i < N + 1; i++) {
		scanf("%d", &cards[i]);
		dp[i] = cards[i];
	}

	for (int i = 2; i < N + 1; i++) {
		for (int j = 1; j < i; j++) {
			dp[i] = bigger(dp[i], dp[j] + dp[i - j]);
		}
	}

	printf("%d", dp[N]);

	return 0;
}