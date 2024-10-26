#define _CRT_SECURE_NO_WARNINGS
#define MIN(a, b) a > b ? b : a
#define ARRAY_LEN 2001
#include <stdio.h>

int WB[ARRAY_LEN][ARRAY_LEN] = { 0, }, WBDP[ARRAY_LEN][ARRAY_LEN] = { 0, };
int BW[ARRAY_LEN][ARRAY_LEN] = { 0, }, BWDP[ARRAY_LEN][ARRAY_LEN] = { 0, };

int main(void) {
	char c;
	int N, M, K, res = ARRAY_LEN * ARRAY_LEN;

	scanf("%d %d %d", &N, &M, &K);

	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < M + 1; j++) {
			scanf(" %c", &c);

			if ((i + j) % 2 == 0) {
				if (c == 'B') {
					WB[i][j] = 1;
					BW[i][j] = 0;
				}
				else {
					WB[i][j] = 0;
					BW[i][j] = 1;
				}
			}
			else {
				if (c == 'W') {
					WB[i][j] = 1;
					BW[i][j] = 0;
				}
				else {
					WB[i][j] = 0;
					BW[i][j] = 1;
				}
			}
			WBDP[i][j] = WBDP[i - 1][j] + WBDP[i][j - 1] - WBDP[i - 1][j - 1] + WB[i][j];
			BWDP[i][j] = BWDP[i - 1][j] + BWDP[i][j - 1] - BWDP[i - 1][j - 1] + BW[i][j];			
		}
	}
		
	for (int i = 0; i < N - K + 1; i++) {
		for (int j = 0; j < M - K + 1; j++) {
			res = MIN(WBDP[i + K][j + K] - WBDP[i][j + K] - WBDP[i + K][j] + WBDP[i][j], res);
			res = MIN(BWDP[i + K][j + K] - BWDP[i][j + K] - BWDP[i + K][j] + BWDP[i][j], res);			
		}
	}

	printf("%d", res);

	return 0;
}