#define _CRT_SECURE_NO_WARNINGS
#define MAX_SIZE 1000001
#include <stdio.h>

int arr[MAX_SIZE];
int temp[MAX_SIZE];
int sorted[MAX_SIZE];

void merge(int start, int mid, int end);
void merge_sort(int start, int end);
int remove_duplicate(int n);
int binary_search(int n, int target);

int main(void) {
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		temp[i] = arr[i];
	}

	if (n == 1) {
		printf("0");
		return 0;
	}

	merge_sort(0, n - 1);

	int index = remove_duplicate(n);

	for (int i = 0; i < n; i++) {
		printf("%d ", binary_search(index + 1, temp[i]));
	}

	return 0;
}


void merge(int start, int mid, int end) {
	int leftsideArrayIndex, rightsideArrayIndex, sortedArrayIndex;
	leftsideArrayIndex = start;
	rightsideArrayIndex = mid + 1;
	sortedArrayIndex = start;

	while (leftsideArrayIndex <= mid && rightsideArrayIndex <= end) {
		if (arr[leftsideArrayIndex] < arr[rightsideArrayIndex]) {
			sorted[sortedArrayIndex++] = arr[leftsideArrayIndex++];
		}
		else {
			sorted[sortedArrayIndex++] = arr[rightsideArrayIndex++];
		}
	}

	if (mid < leftsideArrayIndex) {
		for (int i = rightsideArrayIndex; i <= end; i++) {
			sorted[sortedArrayIndex++] = arr[i];
		}
	}
	else {
		for (int i = leftsideArrayIndex; i <= mid; i++) {
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

int remove_duplicate(int n) {
	int low, high, sortedArrayIndex;
	low = 0;
	high = n;
	sortedArrayIndex = 0;

	while (low != high) {
		if (sorted[sortedArrayIndex] == sorted[low]) {
			low++;
		}
		else {
			sortedArrayIndex++;
			sorted[sortedArrayIndex] = sorted[low];
		}
	}

	return sortedArrayIndex;
}

int binary_search(int n, int target) {
	int low, high, mid;
	low = 0;
	high = n;

	while (low <= high) {
		mid = (low + high) / 2;
		if (sorted[mid] == target) {
			return mid;
		}
		else if (sorted[mid] < target) {
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}
}