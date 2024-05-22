#define _CRT_SECURE_NO_WARNINGS
#define ARRAY_LEN 20
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int arr[ARRAY_LEN + 1][ARRAY_LEN + 1][ARRAY_LEN + 1];

void fillData() {
	for (int i = 0; i < ARRAY_LEN + 1; i++) {
		for (int j = 0; j < ARRAY_LEN + 1; j++) {
			for (int k = 0; k < ARRAY_LEN + 1; k++) {
				if (i <= 0 || j <= 0 || k <= 0) {
					arr[i][j][k] = 1;
				}
				else if (i < j && j < k) {
					arr[i][j][k] = arr[i][j][k - 1] + arr[i][j - 1][k - 1] - arr[i][j - 1][k];
				}
				else {
					arr[i][j][k] = arr[i - 1][j][k] + arr[i - 1][j - 1][k] + arr[i - 1][j][k - 1] - arr[i - 1][j - 1][k - 1];
				}
			}
		}
	}
}

void getResult(int a, int b, int c) {
	if (a <= 0 || b <= 0 || c <= 0) {
		printf("w(%d, %d, %d) = %d\n", a, b, c, 1);
	}
	else if (a <= 20 && b <= 20 && c <= 20) {
		printf("w(%d, %d, %d) = %d\n", a, b, c, arr[a][b][c]);
	}
	else {
		printf("w(%d, %d, %d) = %d\n", a, b, c, arr[ARRAY_LEN][ARRAY_LEN][ARRAY_LEN]);
	}
}

int main(void) {
	int a, b, c;

	fillData();
	
	while (1) {
		scanf("%d %d %d", &a, &b, &c);

		if (a == -1 && b == -1 && c == -1) {
			break;
		}

		getResult(a, b, c);
	}

	return 0;
}