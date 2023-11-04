#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void) {
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		char arr[1001];

		scanf("%s", &arr);

		printf("%c%c\n", arr[0], arr[strlen(arr) - 1]);
	}

	return 0;
}