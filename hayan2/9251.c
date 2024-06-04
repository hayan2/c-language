#define _CRT_SECURE_NO_WARNINGS
#define ARRAY_LEN 1001
#define MAX(a, b) a > b ? a : b
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int dp[ARRAY_LEN][ARRAY_LEN] = { 0, };

int main(void) {
	char str1[ARRAY_LEN] = { NULL, };
	char str2[ARRAY_LEN] = { NULL, };
	int result = 0;

	scanf("%s", str1);
	scanf("%s", str2);

	for (int i = 1; i <= strlen(str1); i++) {
		for (int j = 1; j <= strlen(str2); j++) {
			if (str1[i - 1] == str2[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = MAX(dp[i - 1][j], dp[i][j - 1]);
			}
			result = MAX(result, dp[i][j]);
		}		
	}

	printf("%d", result);

	return 0;
}