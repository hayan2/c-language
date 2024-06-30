#define _CRT_SECURE_NO_WARNINGS
#define STRING_LEN 1000001
#define MOD 20000303
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char s[STRING_LEN];

int main(void) {		
	int strLen = 0, res = 0;

	scanf("%s", s);

	strLen = strlen(s);

	for (int i = 0; i < strLen; i++) {		
		res = (res * 10 + (s[i] - '0')) % MOD;
	}

	printf("%d", res);

	return 0;
}