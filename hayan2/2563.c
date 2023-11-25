#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int area[101][101] = { 0, };
	int result = 0;
	int n;

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		int x, y;

		scanf("%d %d", &x, &y);

		for (int j = x; j < x + 10; j++) {
			for (int k = y; k < y + 10; k++) {
				if (area[j][k] == 0) {
					area[j][k]++;
					result++;
				}
			}
		}
	} 

	printf("%d", result);

	return 0;
}