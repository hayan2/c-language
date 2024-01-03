#define _CRT_SECURE_NO_WARNINGS
#define ARRAY_LEN 1000001
#define CHAR_LEN 6
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct RECORD {
	char name[CHAR_LEN];
	char iao[CHAR_LEN];
}RECORD;

RECORD employee[ARRAY_LEN];

int compare(const void* a, const void* b);

int main(void) {
	int N;

	scanf("%d", &N);
	

	for (int i = 0; i < N; i++) {
		scanf("%s %s", employee[i].name, employee[i].iao);
	}

	qsort(employee, N, sizeof(RECORD), compare);

	for (int i = 0; i < N; i++) {
		if (!strcmp(employee[i].name, employee[i + 1].name)) {
			i++;
		}
		else {
			printf("%s\n", employee[i].name);
		}
	}

	return 0;
}

int compare(const void* a, const void* b) {
	RECORD num1 = *(RECORD*)a;
	RECORD num2 = *(RECORD*)b;

	if (strcmp(num1.name, num2.name) > 0) {
		return 1;
	}
	else if (strcmp(num1.name, num2.name) < 0) {
		return -1;
	}
	else {
		return 0;
	}
}