#define _CRT_SECURE_NO_WARNINGS
#define MIN(a, b) a < b ? a : b
#include <stdio.h>

int main(void) {
	int m, n;
	int sum = 0, min = 100001;
	scanf("%d %d", &m, &n);
	
	for (int i = m; i <= n; i++) {
		for (int j = 2; j <= i; j++) {
			if (i == j) {
				sum += i;
				min = MIN(min, i);
			}						
			if (i % j == 0) {
				break;
			}
		}
	}

	if (sum == 0) {
		printf("-1");
	}
	else {
		printf("%d\n%d", sum, min);
	}

	return 0;
}