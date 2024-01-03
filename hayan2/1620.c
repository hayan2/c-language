#define _CRT_SECURE_NO_WARNINGS
#define ARRAY_LEN 100001
#define CHAR_LEN 21
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char dp[ARRAY_LEN][CHAR_LEN];
char key[ARRAY_LEN][CHAR_LEN];

// ascii code table A to Z - 65 to 90
// int n = atoi(key[0]);

typedef struct POCKETMON {
	char name[CHAR_LEN];
	int index;
}POCKETMON;

int compare(const void* str1, const void* str2);
int string_binary_search(int N, char* key, POCKETMON* pictorial);

int main(void) {
	int N, M;

	scanf("%d %d", &N, &M);

	POCKETMON* pictorial = (POCKETMON*)calloc(N, sizeof(POCKETMON));

	for (int i = 0; i < N; i++) {
		scanf("%s", pictorial[i].name);
		pictorial[i].index = i + 1;
		strcpy(dp[i], pictorial[i].name);
	}

	for (int i = 0; i < M; i++) {
		scanf("%s", key[i]);
	}

	qsort(pictorial, N, sizeof(POCKETMON), compare);
	
	// upper char -> binary_search
	// integer -> atoi, use index
		
	for (int i = 0; i < M; i++) {
		if (key[i][0] >= 65 && key[i][0] <= 90) {
			printf("%d\n", string_binary_search(N, key[i], pictorial));
		}
		else {
			int index = atoi(key[i]) - 1;
			printf("%s\n", dp[index]);
		}
	}
	
	return 0;
}

int compare(const void* str1, const void* str2) {
	POCKETMON string1 = *(POCKETMON*)str1;
	POCKETMON string2 = *(POCKETMON*)str2;

	if (strcmp(string1.name, string2.name) > 0) {
		return 1;
	}
	else if (strcmp(string1.name, string2.name) < 0) {
		return -1;
	}
	else {
		return 0;
	}
}

int string_binary_search(int N, char* key, POCKETMON* pictorial) {
	int low = 0, high = N - 1, mid;

	while (low <= high) {
		mid = (low + high) / 2;
		if (strcmp(pictorial[mid].name, key) == 0) {
			return pictorial[mid].index;
		}
		else if (strcmp(pictorial[mid].name, key) < 0) {
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}

	return 0;
}