#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int N;

	scanf("%d", &N);

	int* arr = (int*)calloc(N, sizeof(int));
	int* dp = (int*)calloc(N, sizeof(int));

	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);		
	}
	
	dp[0] = arr[0];
	int largest = arr[0];

	for (int i = 1; i < N; i++) {
		if (arr[i] + dp[i - 1] < 0 || arr[i] + dp[i - 1] < arr[i]) {
			dp[i] = arr[i];
		}
		else {
			dp[i] = arr[i] + dp[i - 1];
		}

		largest = (largest > dp[i]) ? largest : dp[i];
	}

 	printf("%d", largest);

	return 0;
}