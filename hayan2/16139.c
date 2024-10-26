#define _CRT_SECURE_NO_WARNINGS
#define ARRAY_LEN 200001
#define ASCII_a 97
#define ASCII_z 122
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char S[ARRAY_LEN] = { NULL, };
int arr[ASCII_z - ASCII_a + 1][ARRAY_LEN] = { 0, };

int main(void) {		
	char a;	
	int q, l, r;
	
	scanf("%s", S);

	int SLen = strlen(S);

	for (int i = 1; i <= SLen; i++) {
		arr[S[i - 1] - ASCII_a][i]++;

		for (int j = 0; j < ASCII_z - ASCII_a + 1; j++) {
			arr[j][i] = arr[j][i - 1] + arr[j][i];
		}

	}
	
	scanf("%d", &q);
	
	for (int i = 0; i < q; i++) {
		scanf(" %c", &a);
		scanf("%d %d", &l, &r);		
		printf("%d\n", arr[a - ASCII_a][r + 1] - arr[a - ASCII_a][l]);
	}

	return 0;
}

/*
seungjaehwang
4
a 0 5
a 0 6
a 6 10
a 7 10
*/