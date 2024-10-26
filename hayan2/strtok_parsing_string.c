#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	char str[] = "10+20+30-40";
	char delimeter[] = "+-";
	char* result;
	char parsing[4][16];
	int parsingInt[4][16];
	int i = 0;

	result = strtok(str, delimeter);
		
	while (result != NULL) {
		strcpy(parsing[i++], result);
		result = strtok(NULL, delimeter);
	}

	for (int i = 0; i < 4; i++) {		
		printf("[%d] : %d\n", i, atoi(parsing[i]));
	}


	return 0;
}