#define _CRT_SECURE_NO_WANRINGS
#define max(a, b) (a > b) ? a : b
#include <stdio.h>
#include <stdlib.h>

int arr[501][501];
int dp[501][501];

int main(void) {
	int N;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < i + 1; j++) {
			scanf("%d", arr[i][j]);
		}
	}

	dp[0][0] = arr[0][0];

	for (int i = 1; i < N; i++) {
		for (int j = 0; j < i + 1; j++) {
			if (j == 0) {
				
			}
			else if (j == i) {

			}
			else {
				if (arr[i][j] + dp[i - 1][j] > arr[i][j] + dp[i - 1][j - 1]) {
					dp[i][j] = arr[i][j] + dp[i - 1][j];
				}
			}
		}
	}

	return 0;
}

/*
5
7
3 8
8 1 0
2 7 4 4
4 5 2 6 5
*/

/*
i + 1 j
i + 1 j + 1
*/