#define _CRT_SECURE_NO_WARNINGS
#define ARRAY_LEN 501
#define MAX(a, b) a > b ? a : b
#include <stdio.h>

int main(void) {
	int arr[ARRAY_LEN] = { 0, };
	int dp[ARRAY_LEN] = { 0, };
	int N, idx, result = 0, max = 0;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &idx);
		scanf("%d", &arr[idx]);
	}

	for (int i = 1; i < ARRAY_LEN; i++) {
		if (arr[i] != 0) {
			max = 0;
			for (int j = 0; j < i; j++) {
				if (arr[i] > arr[j] && dp[j] > max) {
					max = dp[j];
				}
			}
			dp[i] = max + 1;
			result = MAX(result, dp[i]);
		}		
	}

	printf("%d", N - result);

	return 0;
}