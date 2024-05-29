#define _CRT_SECURE_NO_WARNINGS
#define ARRAY_LEN 301
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	int arr[ARRAY_LEN];
	int dp[ARRAY_LEN];
	int N, flag = 1;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
		dp[i] = arr[i];
	}

	for (int i = 1; i < N; i++) {
		if (i == 1) {
			if (arr[i - 1] + arr[i] == arr[i]) {				
				flag = 1;				
			}
			else {
				dp[i] += dp[i - 1];
				flag = 0;
			}
			continue;
		}
		
		if (i == 2) {
			if (arr[i - 1] > arr[i - 2]) {
				dp[i] += arr[i - 1];
				flag = 0;
			}
			else {
				dp[i] += arr[i - 2];
				flag = 1;
			}
			continue;
		}

		if (flag == 0) {
			// If it was previously [i] + [i - 1]
			if (arr[i - 1] + dp[i - 3] > dp[i - 2]) {
				dp[i] += (arr[i - 1] + dp[i - 3]);
				flag = 0;
			}
			else {
				dp[i] += dp[i - 2];
				flag = 1;
			}
		}
		else {
			// If it was previously [i] + [i - 2]
			if (dp[i - 1] > dp[i - 2]) {
				dp[i] += dp[i - 1];
				flag = 0;
			}
			else {
				dp[i] += dp[i - 2];
				flag = 1;
			}
		}
	}

	printf("%d", dp[N - 1]);

	return 0;
}