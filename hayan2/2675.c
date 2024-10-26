#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void) {
	char arr[21];
	int t, n;

	scanf("%d", &t);

	for (int i = 0; i < t; i++) {
		
		scanf("%d %s", &n, arr);		

		for (int j = 0; j < strlen(arr); j++) {
			for (int k = 0; k < n; k++) {
				printf("%c", arr[j]);
			}			
		}
		printf("\n");
	}

	return 0;
}