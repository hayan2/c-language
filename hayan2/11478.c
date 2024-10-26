#define _CRT_SECURE_NO_WARNINGS
#define ARRAY_SIZE 1001
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compare(const void* a, const void* b);

int main(void) {
	int len, dpSize, cnt = 0;
	char S[ARRAY_SIZE];
	char** dp;

	scanf("%s", S);

	len = strlen(S);
	dpSize = len * (len + 1) / 2;
	dp = calloc(dpSize, sizeof(char*));

	int idx = 0;
	
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len - i; j++) {
			dp[idx] = calloc((i + 2), sizeof(char));
			strncpy(dp[idx], &S[j], i + 1);
			idx++;
		}
	}

	qsort(dp, dpSize, sizeof(char*), compare);

	for (int i = 0; i < dpSize - 1; i++) {
		if (strcmp(dp[i], dp[i + 1]) == 0) {
			cnt++;
		}
	}
	
	printf("%d", dpSize - cnt);

	return 0;
}

int compare(const void* a, const void* b) {
	return strcmp(*(char**)a, *(char**)b);
}