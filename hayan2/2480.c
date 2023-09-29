#define _CRT_SECURE_NO_WARNINGS
#define MAX(a, b) (a > b) ? a : b
#include <stdio.h>

int main(void) {
	int a, b, c;
	int bigger;

	scanf("%d %d %d", &a, &b, &c);

	if (a == b && b == c) {
		printf("%d", 10000 + a * 1000);
	}
	else if (a == b && b != c || a == c && c != b || b == c && c != a) {
		if (a == b) {
			printf("%d", 1000 + a * 100);
		}
		else if (b == c) {
			printf("%d", 1000 + b * 100);
		}
		else if (a == c) {
			printf("%d", 1000 + a * 100);
		}
		
	}
	else {
		bigger = MAX(a, b);
		bigger = MAX(bigger, c);
		printf("%d", bigger * 100);
	}

	return 0;
}