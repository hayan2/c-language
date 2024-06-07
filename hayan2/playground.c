#define _CRT_SECURE_NO_WARNINGS
#define ARRAY_LEN 200001
#define ASCII_a 97
#define ASCII_z 122
#define M 10000 
#include <stdlib.h> 
#include <stdio.h> 
#include <string.h> 

char S[ARRAY_LEN] = { NULL, };
int alp[ASCII_z - ASCII_a + 1] = { 0, };
int arr[ASCII_z - ASCII_a + 1][ARRAY_LEN] = { 0, };
int q, l, r;

int main(void) {
	/*
	unsigned long long arr;

	arr = 21474836471;

	printf("%lld", arr);
	*/	

	/*
	scanf("%s", S);

	for (int i = 0; i < strlen(S); i++) {
		arr[S[i] - ASCII_a][alp[S[i] - ASCII_a]++]++;
	}
	*/
	char a;
	int b, c;

	scanf("%c %d %d", &a, &b, &c);

	printf("%c %d", a, a - ASCII_a);

	return 0;
}