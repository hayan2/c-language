#define _CRT_SECURE_NO_WARNINGS
#define MOD 42
#include <stdio.h>

int main(void) {
	int arr[43] = { 0, };
	int result = 10;
	int n;

	for (int i = 0; i < 10; i++) {
		scanf("%d", &n);		
		arr[n % MOD]++;		
	}

	for (int i = 0; i < MOD; i++) {
		if (arr[i] != 0) {
			result = result - (arr[i] - 1);
		}
	}

	printf("%d", result);

	return 0;
}