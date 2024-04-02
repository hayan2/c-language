#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

long long factorial(long long n) {	
	if (n == 1 || n == 0) 
		return 1;
	
	return factorial(n - 1) * n;
}

int main(void) {
	long long n;

	scanf("%lld", &n);

	printf("%lld", factorial(n));

	return 0;
}