#define _CRT_SECURE_NO_WARNINGS
#define ARRAY_LEN 2002
#define CHAR_LEN 21
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void* str1, const void* str2) {
	return strcmp((char*)str1, (char*)str2);
}

int main(void) {
	char arr[ARRAY_LEN][CHAR_LEN];	
	char str1[CHAR_LEN];
	char str2[CHAR_LEN];
	int N, flag = 0, idx = 0;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%s %s", str1, str2);

		if (strcmp(str1, "ChongChong") == 0 || strcmp(str2, "ChongChong") == 0)
			flag = 1;
		
		if (flag == 1) {
			strcpy(arr[idx++], str1);
			strcpy(arr[idx++], str2);
		}
	}

	qsort(arr, ARRAY_LEN, CHAR_LEN, compare);

	int cnt = 0;
	
	for (int i = 1; i < idx + 1; i++) {
		if (strcmp(arr[i - 1], arr[i]) != 0 || i == idx)
			cnt++;		
	}

	printf("%d", cnt);
	
	return 0;
}
