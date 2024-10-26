#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void) {
	char arr[12] = { '0', };

	scanf("%s", arr);

	for (int i = strlen(arr); i >= 0; i--) {
		for (int j = 0; j <= i; j++) {
			if (arr[j] < arr[j + 1]) {
				char c = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = c;
			}
		}
	}

	for (int i = 0; i < strlen(arr); i++) {
		putchar(arr[i]);
	}
		
	return 0;
}