#define _CRT_SECURE_NO_WARNINGS
#define MAX(a, b) (a > b) ? a : b
#include <stdio.h>

int main(void) {
	int a, b, c;
	
	scanf("%d %d %d", &a, &b, &c);

	int longest = MAX(a, b);
	longest = MAX(longest, c);

	if (a == b && b == c) {
		printf("%d", a + b + c);
	}
	else if (longest < (a + b + c - longest)) {
		printf("%d", a + b + c);
	}
	else {
		printf("%d", (a + b + c - longest) + (longest - (longest - (a + b + c - longest - 1))));
	}

	return 0;
}