#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int t;
	int a, b;

	scanf("%d", &t);
		
	for (int i = 0; i < t; i++) {
		scanf("%d %d", &a, &b);

		int units = 1;
		for (int j = 0; j < b; j++) {
			units = units * a % 10;
		}

		if (units % 10 == 0) {
			printf("10\n");
		}
		else {
			printf("%d\n", units % 10);
		}
	}
 
	return 0;
}