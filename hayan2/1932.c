#define _CRT_SECURE_NO_WARNINGS
#define max(a, b) (a > b) ? a : b
#include <stdio.h>
#include <stdlib.h>

// acmicpc.net 1932

int arr[501][501];
int dp[501][501];

int main(void) {
	int N;
	
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < i + 1; j++) {
			scanf("%d", &arr[i][j]);
			dp[i][j] = arr[i][j];
		}
	}

	

	return 0;
}