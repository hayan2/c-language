#define _CRT_SECURE_NO_WARNINGS
#define THREE_SUGAR 3
#define FIVE_SUGAR 5
#include <stdio.h>

int main(void) {
	int n, count = 0, flag = 0, res = 0;

	scanf("%d", &n);

	for (int i = 0; i < 1666; i++) {
		if (flag == 0 && res < n) {
			res += FIVE_SUGAR;
			count++;
		}
		else {
			flag = 1;
			res -= FIVE_SUGAR;
			count--;
			if ((n - res) % 3 == 0) {
				count += (n - res) / 3;
				break;
			}
			if (res <= 0) {
				count = -1;
				break;
			}
		}

		if (res == n) {
			break;
		}
	}

	printf("%d", count);

	return 0;
}