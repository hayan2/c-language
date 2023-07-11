#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// binomial coefficient formula
// input --- n, k  || ( 1 <= n <= 10, 0 <= k <= n )
// n! / (k! (n - k)!)

int fact(int n) {
	int result = 1;

	for (int i = 1; i <= n; i++) {
		result *= i;
	}
	
	return result;
}

int main(void) {
	int n, k;

	scanf("%d %d", &n, &k);

	int N = fact(n);
	int K = fact(k);
	int nk = fact(n - k);

	printf("%d", N / (K * nk));
	
	return 0;
}