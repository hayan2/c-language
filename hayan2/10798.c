#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
	char str[5][15] = { 0, };

	for (int i = 0; i < 5; i++) {
		scanf("%s", str[i]);
	}

	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 5; j++) {
			if (str[j][i] != '\0') {
				putchar(str[j][i]);
			}
		}
	}

	return 0;
}