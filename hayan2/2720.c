#define _CRT_SECURE_NO_WARNINGS
#define LEN 4
#include <stdio.h>

int main(void) {
	int cent[LEN] = { 25, 10, 5, 1 };
	int res[LEN] = { 0, };
	int t;

	scanf("%d", &t);

	for (int i = 0; i < t; i++) {
		int c;
		scanf("%d", &c);
		for (int j = 0; j < LEN; j++) {
			while (c >= cent[j]) {
				res[j]++;
				c -= cent[j];
			}
		}
		for (int j = 0; j < LEN; j++) {
			printf("%d ", res[j]);
			res[j] = 0;
		}
		printf("\n");
	}

	return 0;
}