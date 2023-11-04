#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void) {
	char arr[101];
	int n, result = 0;

	scanf("%d", &n);
	scanf("%s", &arr);
	
	for (int i = 0; i < n; i++) {
		result += arr[i] - 48;
	}

	printf("%d", result);

	return 0;
}