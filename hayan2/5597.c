#define _CRT_SECURE_NO_WARNINGS
#define LEN 28
#include <stdio.h>

int main(void) {
	int arr[31] = { 0, };
	int n;	

	for (int i = 0; i < LEN; i++) {
		scanf("%d", &n);
		arr[n] = 1;
	}

	for (int i = 1; i < 31; i++) {
		if (arr[i] == 0) {
			printf("%d\n", i);
		}
	}

	return 0;
}