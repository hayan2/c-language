#define _CRT_SECURE_NO_WARNINGS
#define WEIGHT_LEN 35
#define MARBLE_LEN 11
#include <stdio.h>
#include <stdlib.h>

int dp[WEIGHT_LEN][WEIGHT_LEN] = { 0, };
int weight[WEIGHT_LEN];
int marble[MARBLE_LEN];

// wrong
int main(void) {
	int w, m;

	scanf("%d", &w);

	for (int i = 1; i <= w; i++) {
		scanf("%d", &weight[i]);
	}

	scanf("%d", &m);

	for (int i = 1; i <= m; i++) {
		scanf("%d", &marble[i]);
	}

	for (int i = 1; i <= w; i++) {
		for (int j = i; j <= w; j++) {
			dp[i][j] = dp[i][j - 1] + weight[j];
		}
	}

	for (int l = 1; l <= m; l++) {
		int flag = 0;

		for (int i = 0; i <= w; i++) {
			for (int j = 1; j <= w - i; j++) {
				for (int k = j; k <= i + j; k++) {
					if (marble[l] == dp[j][i + j] || marble[l] == abs((dp[k + 1][i + j]) - (dp[j][k]))) {
						flag = 1;
						break;
					}
				}
				if (flag) {
					break;
				}
			}
			if (flag) {
				break;
			}
		}

		if (flag) {
			printf("Y ");
		}
		else {
			printf("N ");
		}
	}

	return 0;
}