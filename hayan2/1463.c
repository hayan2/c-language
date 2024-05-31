#define _CRT_SECURE_NO_WARNINGS
#define ARRAY_LEN 1000001
#define MIN(a, b) (a > b) ? b : a
#include <stdio.h>
#include <stdlib.h>

int dp[ARRAY_LEN];

int main(void) {	
	int X, temp = 1;

	scanf("%d", &X);
	
	if (X == 1) {
		printf("0");
		exit(0);
	}

	dp[1] = dp[2] = dp[3] = 1;
	
	for (int i = 4; i <= X; i++) {		
		dp[i] = dp[i - 1] + 1;
		if (i % 2 == 0) {
			dp[i] = MIN(dp[i / 2] + 1, dp[i]);
		}
		if (i % 3 == 0) {
			dp[i] = MIN(dp[i / 3] + 1, dp[i]);
		}
	}

	printf("%d", dp[X]);

	return 0;
}