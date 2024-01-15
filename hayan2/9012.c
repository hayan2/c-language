#define _CRT_SECURE_NO_WARNINGS
#define ARRAY_SIZE 51
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
	char arr[ARRAY_SIZE];
	int N;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		int res = 0;
		scanf("%s", arr);
		for (int j = 0; j < strlen(arr); j++) {
			if (arr[j] == '(') {
				res++;
			}
			else if (arr[j] == ')') {
				res--;
			}
			if (res < 0) {
				break;
			}
		}
		if (res == 0) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
	}

	return 0;
}