#define _CRT_SECURE_NO_WARNINGS
#define CHAR_LEN 21
#define ARRAY_SIZE 100001
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char arr[ARRAY_SIZE][CHAR_LEN];
char sorted[ARRAY_SIZE][CHAR_LEN];
char str[CHAR_LEN];

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

	for (int i = start; i <= end; i++) {
		strcpy(arr[i], sorted[i]);
	}
}

void merge_sort(int start, int end) {
	int mid = (start + end) / 2;

	if (start < end) {
		merge_sort(start, mid);
		merge_sort(mid + 1, end);
		merge(start, mid, end);
	}
}

int main(void) {
	int N, idx = 0, cnt = 0;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%s", str);

		if (strcmp(str, "ENTER") != 0) 
			strcpy(arr[idx++], str);

		if (i == N - 1 || strcmp(str, "ENTER") == 0) {
			merge_sort(0, idx - 1);
			for (int j = 1; j <= idx; j++) {
				if (strcmp(arr[j - 1], arr[j]) != 0 || j == idx) {
					cnt++;
				}
			}
			idx = 0;
		}
	}

	printf("%d", cnt);

	return 0;
}