#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	char str[55];

	scanf(" %s", &str);
	
	for (int i = 0; i <= strlen(str); i++) {
		if (str[i] == '\0') {
			printf("?\?!");
			break;
		}
		else {
			printf("%c", str[i]);
		}
	}
		
	
	return 0;
}