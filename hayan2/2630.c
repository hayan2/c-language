#define _CRT_SECURE_NO_WARNINGS
#define ARRAY_LEN 129
#define WHITE 0
#define BLUE 1
#include <stdio.h>

int arr[ARRAY_LEN][ARRAY_LEN] = { 0, };
int white = 0, blue = 0;

void getResult(int x, int y, int N);

int main(void) {
	int N;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	getResult(0, 0, N);

	printf("%d\n%d", white, blue);

	return 0;
}

void getResult(int x, int y, int N) {
	int flagB = 1, flagW = 1;

	for (int i = x; i < x + N; i++) {
		for (int j = y; j < y + N; j++) {
			if (arr[i][j] == WHITE) {
				flagB = 0;
			}
			if (arr[i][j] == BLUE) {
				flagW = 0;
			}
		}
	}

	if (flagB) {
		blue++;

		return;
	}
	if (flagW) {
		white++;

		return;
	}

	getResult(x, y, N / 2);
	getResult(x + N / 2, y, N / 2);
	getResult(x, y + N / 2, N / 2);
	getResult(x + N / 2, y + N / 2, N / 2);

}