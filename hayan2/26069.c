#define _CRT_SECURE_NO_WARNINGS
#define ARRAY_LEN 2002
#define CHAR_LEN 21
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char arr[ARRAY_LEN][CHAR_LEN];
char sorted[ARRAY_LEN][CHAR_LEN];

int compare(const void* str1, const void* str2) {
	return strcmp((char*)str1, (char*)str2);
}

void merge(int start, int mid, int end) {
	int leftSideArrayIndex, rightSideArrayIndex, sortedArrayIndex;
	leftSideArrayIndex = start;
	rightSideArrayIndex = mid + 1;
	sortedArrayIndex = start;

	while (leftSideArrayIndex <= mid && rightSideArrayIndex <= end) {
		if (strcmp(arr[leftSideArrayIndex], arr[rightSideArrayIndex]) < 0)
			strcpy(sorted[sortedArrayIndex++], arr[leftSideArrayIndex++]);
		else
			strcpy(sorted[sortedArrayIndex++], arr[rightSideArrayIndex++]);
	}

	if (mid < leftSideArrayIndex) {
		for (int i = rightSideArrayIndex; i <= end; i++)
			strcpy(sorted[sortedArrayIndex++], arr[i]);
	}
	else {
		for (int i = leftSideArrayIndex; i <= mid; i++)
			strcpy(sorted[sortedArrayIndex++], arr[i]);
	}

	for (int i = start; i <= end; i++)
		strcpy(arr[i], sorted[i]);
}

void merge_sort(int start, int end) {
	int mid = (start + end) / 2;

	if (start < end) {
		merge_sort(start, mid);
		merge_sort(mid + 1, end);
		merge(start, mid, end);
	}
}


int binary_search(char arr[][CHAR_LEN], int start, int end, char* key) {
	while (start <= end) {
		int mid = (start + end) / 2;

		if (strcmp(arr[mid], key) == 0) {
			return 1;
		}
		else if (strcmp(arr[mid], key) < 0) {
			start = mid + 1;
		}
		else if (strcmp(arr[mid], key) > 0) {			
			end = mid - 1;
		}
	}

	return -1;
}

int main(void) {
	
	char str1[CHAR_LEN];
	char str2[CHAR_LEN];
	int N, idx = 0, cnt = 0, flag = 0;

	strcpy(arr[idx++], "ChongChong");
	cnt++;
	
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		merge_sort(0, idx - 1);

		scanf("%s %s", str1, str2);

		int cmp1 = binary_search(arr, 0, idx, str1);
		int cmp2 = binary_search(arr, 0, idx, str2);

		if ((cmp1 == 1 && cmp2 == -1) || (cmp1 == -1 && cmp2 == 1)) {
			(cmp1 < cmp2) ? strcpy(arr[idx++], str1) : strcpy(arr[idx++], str2);
			cnt++;
		}
	}

	printf("%d", cnt);

	return 0;
}
