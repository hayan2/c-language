#define _CRT_SECURE_NO_WARNINGS
#define MAX(a, b) (a > b) ? a : b
#include <stdio.h>

int main(void) {
	while (1) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		if (a == 0 && b == 0 && c == 0) {
			break;
		}

		int longest = MAX(a, b);
		longest = MAX(longest, c);

		if (longest < (a + b + c - longest)) {
			if (a == b && b == c) {
				printf("Equilateral\n");
			}
			else if (a == b || b == c || a == c) {
				printf("Isosceles\n");
			}
			else if (a != b && b != c) {
				printf("Scalene\n");
			}
		}
		else {
			printf("Invalid\n");
		}
	}

	return 0;
}