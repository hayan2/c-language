#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
	char arr[101] = { 0, };
	int n, b, idx = 0;

	scanf("%d %d", &n, &b);

	while (n) {
		if (n % b == 0) {
			arr[idx++] = '0';
		}
		else {
			arr[idx++] = n % b;
		}
		n /= b;
	}

	for (int i = strlen(arr) - 1; i >= 0; i--) {
		if (arr[i] >= 0 && arr[i] <= 9) {
			printf("%c", arr[i] + '0');
		}
		else if (arr[i] >= 10 && arr[i] <= 35) {
			printf("%c", arr[i] + 55);
		}
		else if (arr[i] == '0') {
			printf("0");
		}
	}

	return 0;
}