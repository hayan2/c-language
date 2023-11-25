#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void) {
	char arr[101];
	int cnt = 0;

	gets(arr);

	for (int i = 0; i < strlen(arr); i++) {
		if (arr[i] == 'c' && arr[i + 1] == '=') {
			i++;
			cnt++;
		}
		else if (arr[i] == 'c' && arr[i + 1] == '-') {
			i++;
			cnt++;
		}
		else if (arr[i] == 'd' && arr[i + 1] == 'z' && arr[i + 2] == '=') {
			i += 2;
			cnt++;
		}
		else if (arr[i] == 'd' && arr[i + 1] == '-') {
			i++;
			cnt++;
		}
		else if (arr[i] == 'l' && arr[i + 1] == 'j') {
			i++;
			cnt++;
		}
		else if (arr[i] == 'n' && arr[i + 1] == 'j') {
			i++;
			cnt++;
		}
		else if (arr[i] == 's' && arr[i + 1] == '=') {
			i++;
			cnt++;
		}
		else if (arr[i] == 'z' && arr[i + 1] == '=') {
			i++;
			cnt++;
		}
		else {
			cnt++;
		}
	}

	printf("%d", cnt);

	return 0;
}