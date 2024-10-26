#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void) {
	char arr[101];

	gets(arr);

	for (int i = 97; i < 123; i++) {
		for (int j = 0; j < strlen(arr); j++) {
			if (i == arr[j]) {
				printf("%d ", j);
				break;
			}
			if (j == strlen(arr) - 1) {
				printf("-1 ");
				break;
			}
		}
	}

	return 0;
}