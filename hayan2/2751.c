#define _CRT_SECURE_NO_WARNINGS
#define MAX_SIZE 1000001
#include <stdio.h>

int sorted[MAX_SIZE] = { 0, };
int arr[MAX_SIZE] = { 0, };

// merge sort

void merge(int start, int mid, int end);
void merge_sort(int start, int end);

int main(void) {
	int n;

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	if (n == 1) {
		printf("%d", arr[0]);
		
		return 0;
	}

	merge_sort(0, n - 1);

	for (int i = 0; i < n; i++) {
		printf("%d\n", sorted[i]);
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
			sorted[sortedArrayIndex++] = arr[leftSideArrayIndex++];
		}
		else {
			sorted[sortedArrayIndex++] = arr[rightSideArrayIndex++];
		}
	}

	if (mid < leftSideArrayIndex) {
		for (int i = rightSideArrayIndex; i <= end; i++) {
			sorted[sortedArrayIndex++] = arr[i];
		}
	}
	else {
		for (int i = leftSideArrayIndex; i <= mid; i++) {
			sorted[sortedArrayIndex++] = arr[i];
		}
	}

	for (int i = start; i <= end; i++) {
		arr[i] = sorted[i];
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