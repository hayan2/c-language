#define _CRT_SECURE_NO_WARNINGS
#define MAX(a, b) (a > b) ? a : b
#include <stdio.h>

int main(void) {
	int index = 0, max = -1;
	int n;

	for (int i = 0; i < 9; i++) {
		scanf("%d", &n);
		if (max < n) {
			max = n;
			index = i + 1;
		}
	}

	printf("%d\n%d", max, index);

	return 0;
}