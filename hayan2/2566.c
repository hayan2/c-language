#define _CRT_SECURE_NO_WARNINGS
#define MAX(a, b) (a > b) ? a : b
#include <stdio.h>

int main(void) {
	int n, max = 0;
	int row, col;

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			scanf("%d", &n);
			if (max <= n) {
				max = MAX(max, n);
				row = i;
				col = j;
			}
		}
	}
	printf("%d\n%d %d", max, ++row, ++col);

	return 0;
}