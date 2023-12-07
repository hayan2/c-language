#define _CRT_SECURE_NO_WARNINGS
#define MIN(a, b) a < b ? a : b
#define BOARD 8
#include <stdio.h>

int main(void) {
	char chess[51][51] = { 0, };
	int n, m, res = 65;
	
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		scanf("%s", chess[i]);
	}
	
	for (int i = 0; i <= n - BOARD; i++) {
		for (int j = 0; j <= m - BOARD; j++) {
			int bwCount = check_bw(chess, i, j);
			int wbCount = check_wb(chess, i, j);
			res = MIN(res, bwCount);
			res = MIN(res, wbCount);
		}
	}

	printf("%d", res);

	return 0;
}

int check_bw(char chess[][51], int x, int y) {
	char color = 'B';
	int count = 0;

	for (int i = y; i < (y + BOARD); i++) {
		for (int j = x; j < (x + BOARD); j++) {
			if (chess[j][i] != color) {
				count++;
			}

			color = (color == 'B') ? 'W' : 'B';
		}	
		color = (color == 'B') ? 'W' : 'B';
	}

	return count;
}

int check_wb(char chess[][51], int x, int y) {	
	char color = 'W';
	int count = 0;

	for (int i = y; i < (y + BOARD); i++) {
		for (int j = x; j < (x + BOARD); j++) {
			if (chess[j][i] != color) {
				count++;
			}

			color = (color == 'B') ? 'W' : 'B';
		}
		color = (color == 'B') ? 'W' : 'B';
	}

	return count;
}