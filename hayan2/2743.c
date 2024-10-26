#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void) {
	char arr[101];

	gets(arr);

	printf("%d", strlen(arr));

	return 0;
}