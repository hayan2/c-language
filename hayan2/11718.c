#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void) {
	char arr[101];

	while (gets(arr) != NULL) {
		printf("%s\n", arr);
	}

	return 0;
}