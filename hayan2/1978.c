#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
	int t, cnt = 0;

	scanf("%d", &t);

	for (int i = 0; i < t; i++) {
		int n;
		scanf("%d", &n);
		for (int j = 2; j <= n; j++) {
			if (n == 2) {
				cnt++;
				break;
			}
			if (n % j == 0) {
				break;
			}
			if (j == n - 1) {
				cnt++;
			}
		} 
	}
	printf("%d", cnt);

	return 0;
}