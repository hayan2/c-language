#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

char arr[1000001];

int main(void) {
	int result = 0, i = 0;
	char c;

	while ((c = getchar()) != '\n') {
		arr[i++] = c;
		if (c == ' ') {
			result++;
		}
	}

	if (arr[0] == ' ') {
		result--;
	}
	if (arr[strlen(arr) - 1] == ' ') {
		result--;
	}

	printf("%d\n", result + 1);

	return 0;
}