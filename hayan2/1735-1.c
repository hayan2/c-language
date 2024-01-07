#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int get_gcd(int a, int b);

int main(void) {
	int A1, A2, B1, B2;

	scanf("%d %d", &A1, &A2);
	scanf("%d %d", &B1, &B2);

	int GCD, denominator, numerator;

	denominator = (A2 * B2);
	numerator = (A1 * B2) + (B1 * A2);
	GCD = get_gcd(denominator, numerator);
	
	printf("%d %d", numerator / GCD, denominator / GCD);
		
	return 0;
}

int get_gcd(int a, int b) {
	return b ? get_gcd(b, a % b) : a;
}