#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int a1, a2, a3;

	scanf("%d %d %d", &a1, &a2, &a3);

	if (a1 == a2 && a2 == a3) {
		printf("Equilateral");
	}
	else if ((a1 + a2 + a3) == 180) {
		if (a1 == a2 || a2 == a3 || a1 == a3) {
			printf("Isosceles");
		}
		else {
			printf("Scalene");
		}
	}
	else {
		printf("Error");
	}

	return 0;
}