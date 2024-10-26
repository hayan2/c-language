#define _CRT_SECURE_NO_WARNINGS
#define ARRAY_LEN 10001
#define STRING_LEN 501
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char str[ARRAY_LEN][STRING_LEN];
char keys[ARRAY_LEN][STRING_LEN];

int string_binary_search(int N, char* key);

int main(void) {	
	int N, M;

	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		scanf("%s", str[i]);
	}

	for (int i = 0; i < M; i++) {
		scanf("%s", keys[i]);
	}
	
	qsort(str, N, STRING_LEN, (int (*)(const void*, const void*))strcmp);
	
	int res = 0;

	for (int i = 0; i < M; i++) {
		res += string_binary_search(N, keys[i]);
	}

	printf("%d", res);

	return 0;
}


int string_binary_search(int N, char* key) {
	int low = 0, high = N - 1, mid;

	while (low <= high) {
		mid = (low + high) / 2;
		if (strcmp(str[mid], key) == 0) {
			return 1;
		}
		else if (strcmp(str[mid], key) < 0) {
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}

	return 0;
}