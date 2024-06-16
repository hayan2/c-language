#define _CRT_SECURE_NO_WARNINGS
#define ARRAY_LEN 2001
#define MIN(a, b) a > b ? b : a
#include <stdio.h>

int WB[ARRAY_LEN][ARRAY_LEN] = { 0, }, WBS[ARRAY_LEN][ARRAY_LEN] = { 0, };
int BW[ARRAY_LEN][ARRAY_LEN] = { 0, }, BWS[ARRAY_LEN][ARRAY_LEN] = { 0, };

int main(void) {
	char c;
	int N, M, K;

	scanf("%d %d %d", &N, &M, &K);

	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < M + 1; j++) {
			scanf(" %c", &c);

			if ((i + j) % 2 == 0) {
				if (c == 'B') {
					BW[i][j] = 0;
					WB[i][j] = 1;
				}
				else {
					BW[i][j] = 1;
					WB[i][j] = 0;
				}
			}
			else {
				if (c == 'B') {
					BW[i][j] = 1;
					WB[i][j] = 0;
				}
				else {
					BW[i][j] = 0;
					WB[i][j] = 1;
				}
			}
			BWS[i][j] = BWS[i - 1][j] + BWS[i][j - 1] - BWS[i - 1][j - 1] + BW[i][j];
			WBS[i][j] = WBS[i - 1][j] + WBS[i][j - 1] - WBS[i - 1][j - 1] + WB[i][j];
		}
	}

	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < M + 1; j++) {
			printf("%d ", BWS[i][j]);			
		}
		printf("\n");
	}

	return 0;
}
