#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
	int n;
	
	while (1) {
		scanf("%d", &n);

		if (n == 0) {
			break;
		}
		int nDigits = floor(log10(abs(n))) + 1;
		
		switch (nDigits) {
		case 1:
			printf("yes\n");
			break;
		case 2:
			if ((n / 10) == (n % 10)) {
				printf("yes\n");
			}
			else {
				printf("no\n");
			}
			break;
		case 3:
			if ((n % 10) == (n / 100)) {
				printf("yes\n");
			}
			else {
				printf("no\n");
			}
			break;
		case 4:
			if ((n % 10) == (n / 1000) && ((n / 100) % 10) == ((n % 100) / 10)) {
				printf("yes\n");
			}
			else {
				printf("no\n");
			}
			break;
		case 5:
			if ((n % 10) == (n / 10000) && ((n / 10) % 10) == (n / 1000) % 10) {
				printf("yes\n");
			}
			else {
				printf("no\n");
			}
			break;
		}
	}

	return 0;
}