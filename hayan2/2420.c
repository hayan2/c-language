#define _CRT_SECURE_NO_WARNINGS
#define max(a, b) (a > b) ? a : b
#define min(a, b) (a < b) ? a : b
#include <stdio.h>
#include <math.h>

// sub domain -- seunghwan.royal.gov.sw   or   kyuhyun.royal.gov.sw
// combine	  -- couple.royal.gov.sw			

int main(void) {
	long long n, m;

	scanf("%lld %lld", &n, &m);

	long long max = max(n, m);
	long long min = min(n, m);

	printf("%lld", max - min);

	return 0;
}
