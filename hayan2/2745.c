#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>

int my_pow(int base, int exp);

int main(void) {
	char arr[101];
	int n, result = 0, exp = 0;

	scanf("%s %d", arr, &n);

	for (int i = strlen(arr) - 1; i >= 0; i--) {
		if (arr[i] >= '0' && arr[i] <= '9') {
			result += (arr[i] - '0') * my_pow(n, exp++);
		}
		else if (arr[i] >= 'A' && arr[i] <= 'Z') {
			result += (arr[i] - 55) * my_pow(n, exp++);
		}
	}

	printf("%d", result);

	return 0;
}

int my_pow(int base, int exp) {
	int res = 1;
	while (exp) {
		if (exp & 1) {
			res *= base;
		}
		exp >>= 1;
		base *= base;
	}

	return res;
}