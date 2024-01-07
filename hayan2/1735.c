#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int A1, A2, B1, B2;

	scanf("%d %d", &A1, &A2);
	scanf("%d %d", &B1, &B2);

	int cnt = 2;
	int denominator, numerator;

	denominator = A2 * B2;
	numerator = (A1 * B2) + (B1 * A2);

	while (cnt <= denominator && cnt <= numerator) {
		if ((denominator % cnt != 0) || (numerator % cnt != 0)) {
			cnt++;
		}
		else {
			denominator /= cnt;
			numerator /= cnt;
		}
	}

	printf("%d %d", numerator, denominator);

	return 0;
}