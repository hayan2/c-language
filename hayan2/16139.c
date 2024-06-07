#define _CRT_SECURE_NO_WARNINGS
#define ARRAY_LEN 200001
#define ASCII_a 97
#define ASCII_z 122
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
	char S[ARRAY_LEN] = { NULL, };
	int alp[ASCII_z - ASCII_a + 1] = { -1, };
	int arr[ASCII_z - ASCII_a + 1][ARRAY_LEN] = { 0, };
	int q, l, r;

	scanf("%s", S);

	for (int i = 0; i < strlen(S); i++) {
		arr[S[i] - ASCII_a][alp[S[i] - ASCII_a]++]++;
	}

	scanf("%d", &q);

	for (int i = 0; i < q; i++) {
		
	}

	return 0;
}