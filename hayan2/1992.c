#define _CRT_SECURE_NO_WARNINGS
#define ARRAY_LEN 65
#define RESULT_LEN 4096
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char arr[ARRAY_LEN][ARRAY_LEN];
char res[RESULT_LEN];

void getResult(int x, int y, int N);

int main(void) {
	int N;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf(" %c", &arr[i][j]);
		}
	}

	getResult(0, 0, N);

	printf("%s", res);

	return 0;
}

void getResult(int x, int y, int N) {
	int flagW = 1, flagB = 1;

	for (int i = x; i < x + N; i++) {
		for (int j = y; j < y + N; j++) {
			if (arr[i][j] == '0') {
				flagB = 0;
			}
			else if (arr[i][j] == '1') {
				flagW = 0;
			}
		}

		if (flagB == 0 && flagW == 0) {
			break;
		}
	}

	if (flagB) {		
		strcat(res, "1");		

		return;
	}
	if (flagW) {		
		strcat(res, "0");		

		return;
	}
	
	strcat(res, "(");
	getResult(x, y, N / 2);	
	getResult(x, y + N / 2, N / 2);	
	getResult(x + N / 2, y, N / 2);			
	getResult(x + N / 2, y + N / 2, N / 2);	
	strcat(res, ")");
}