#define _CRT_SECURE_NO_WARNINGS
#define ARRAY_LEN 2188
#define RES_LEN 3
#define RES_M1 0
#define RES_0 1
#define RES_1 2
#include <stdio.h>

int arr[ARRAY_LEN][ARRAY_LEN];
int res[RES_LEN] = { 0, };

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

	printf("%d\n%d\n%d", res[RES_M1], res[RES_0], res[RES_1]);

	return 0;
}

void getResult(int x, int y, int N) {
	int flagM1 = 1, flag0 = 1, flag1 = 1;
	for (int i = x; i < x + N; i++) {
		for (int j = y; j < y + N; j++) {
			if (arr[i][j] == -1) {
				flag0 = 0;
				flag1 = 0;
			}
			else if (arr[i][j] == 0) {
				flagM1 = 0;
				flag1 = 0;
			}
			else if (arr[i][j] == 1) {
				flagM1 = 0;
				flag0 = 0;
			}
		}
	}

	if (flagM1) {
		res[RES_M1]++;

		return;
	}
	if (flag0) {
		res[RES_0]++;

		return;
	}
	if (flag1) {
		res[RES_1]++;

		return;
	}

	getResult(x, y, N / 3);
	getResult(x + N / 3, y, N / 3);
	getResult(x + (N * 2) / 3, y, N / 3);
	getResult(x, y + N / 3, N / 3);
	getResult(x, y + (N * 2) / 3, N / 3);
	getResult(x + N / 3, y + N / 3, N / 3);
	getResult(x + N / 3, y + (N * 2) / 3, N / 3);
	getResult(x + (N * 2) / 3, y + N / 3, N / 3);
	getResult(x + (N * 2) / 3, y + (N * 2) / 3, N / 3);
}