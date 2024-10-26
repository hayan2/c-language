#define _CRT_SECURE_NO_WARNINGS
#define THREE_SUGAR 3
#define FIVE_SUGAR 5
#include <stdio.h>

int main(void) {
	int n, count = 0;

	scanf("%d", &n);

	while (n > 0) {
		if (n % FIVE_SUGAR == 0) {
			count += (n / FIVE_SUGAR);
			n = 0;
			break;
		}
		n -= THREE_SUGAR;
		count++;
	}

	if (n == 0) {
		printf("%d", count);
	}
	else {
		printf("-1");
	}

	return 0;
}