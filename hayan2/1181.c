#define _CRT_SECURE_NO_WARNINGS
#define ARRAY_LEN 20001
#define CHAR_LEN 51
#include <stdio.h>
#include <string.h>

char sorted[ARRAY_LEN][CHAR_LEN];
char arr[ARRAY_LEN][CHAR_LEN];

void merge(int start, int mid, int end);
void merge_sort(int start, int end);

int main(void) {
	
	int n;

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%s", arr[i]);
	}

	merge_sort(0, n - 1);

	printf("\n");
	for (int i = 0; i < n; i++) {
		printf("%s\n", sorted[i]);
	}

	return 0;
}

void merge(int start, int mid, int end) {
	int leftSideArrayIndex, rightSideArrayIndex, sortedArrayIndex;
	leftSideArrayIndex = start;
	rightSideArrayIndex = mid + 1;
	sortedArrayIndex = start;

	while (leftSideArrayIndex <= mid && rightSideArrayIndex <= end) {
		if (arr[leftSideArrayIndex] <= arr[rightSideArrayIndex]) {
			strcpy(sorted[sortedArrayIndex++], arr[leftSideArrayIndex++]);
		}
		else {
			strcpy(sorted[sortedArrayIndex++], arr[rightSideArrayIndex++]);			
		}
	}

	if (mid < leftSideArrayIndex) {
		for (int i = rightSideArrayIndex; i <= end; i++) {
			strcpy(sorted[sortedArrayIndex++], arr[i]);			
		}
	}
	else {
		for (int i = leftSideArrayIndex; i <= mid; i++) {
			strcpy(sorted[sortedArrayIndex++], arr[i]);
		}
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