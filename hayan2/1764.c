#define _CRT_SECURE_NO_WARNINGS
#define ARRAY_SIZE 500001
#define CHAR_SIZE 21
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char str1[ARRAY_SIZE][CHAR_SIZE];
char str2[ARRAY_SIZE][CHAR_SIZE];
char res[ARRAY_SIZE][CHAR_SIZE];

int string_binary_search(int N, char* key, int res);

int main(void) {
	int N, M, result = 0, resIndex = 0;

	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		scanf("%s", str1[i]);
	}

	for (int i = 0; i < M; i++) {
		scanf("%s", str2[i]);
	}

	qsort(str1, N, CHAR_SIZE, (int (*)(const void*, const void*))strcmp);
	qsort(str2, M, CHAR_SIZE, (int (*)(const void*, const void*))strcmp);

	for (int i = 0; i < M; i++) {
		int temp = result;
		result = string_binary_search(N, str2[i], result);
		if (temp != result) {
			strcpy(res[resIndex++], str2[i]);
		}		
	}

	printf("%d\n", resIndex);
	for (int i = 0; i < resIndex; i++) {
		printf("%s\n", res[i]);
	}

	return 0;
}

int string_binary_search(int N, char* key, int res) {
	int low = 0, high = N - 1;

	while (low <= high) {
		int mid = (low + high) / 2;
		if (strcmp(str1[mid], key) == 0) {
			return ++res;
		}
		else if (strcmp(str1[mid], key) < 0) {
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}

	return res;
}