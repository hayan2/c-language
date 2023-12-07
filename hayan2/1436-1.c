#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int n, count = 0, idx = 666, res = 0;

	scanf("%d", &n);

	while (n != count) {
		int temp = idx;
		while (temp != 0) {
			if (temp % 1000 == 666) {
				count++;
				res = idx;
				break;
			}
			else {
				temp /= 10;
			}
		}
		idx++;
	}

	printf("%d", res);

	return 0;
}