#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void) {
	char arr[101];
	int check = 1;
	
	gets(arr);

	int len = strlen(arr);

	for (int i = 0; i < len / 2; i++) {
		if (check != 0 && arr[i] != arr[len - i - 1]) {
			check = 0;
		}		
	}

	printf("%d", check);

	return 0;
}