#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void) {
	char arr[1001];
	int n;

	gets(arr);
	scanf("%d", &n);

	printf("%c", arr[n - 1]);
		
	return 0;
}