#define _CRT_SECURE_NO_WARNINGS
#define MAX_SIZE 500001
#include <stdio.h>

int card[MAX_SIZE];
int target[MAX_SIZE];
int sorted[MAX_SIZE];

void merge(int low, int mid, int high);
void merge_sort(int low, int high);
int binary_search(int N, int key);

int main(void) {
	int N, M;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &card[i]);
	}

	if (N == 1) {
		sorted[0] = card[0];
	}

	scanf("%d", &M);

	for (int i = 0; i < M; i++) {
		scanf("%d", &target[i]);
	}

	if (N == 1 && M == 1) {
		printf("%d", (card[0] == target[0]) ? 1 : 0);
		return 0;
	}

	merge_sort(0, N - 1);
	
	for (int i = 0; i < M; i++) {
		if (binary_search(N - 1, target[i]) == 1) {
			printf("1 ");
		}
		else {
			printf("0 ");
		}		
	}

	return 0;
}

void merge(int low, int mid, int high) {
	int leftsideArrayIndex, rightsideArrayIndex, sortedArrayIndex;
	leftsideArrayIndex = low;
	rightsideArrayIndex = mid + 1;
	sortedArrayIndex = low;

	while (leftsideArrayIndex <= mid && rightsideArrayIndex <= high) {
		if (card[leftsideArrayIndex] < card[rightsideArrayIndex]) {
			sorted[sortedArrayIndex++] = card[leftsideArrayIndex++];
		}
		else {
			sorted[sortedArrayIndex++] = card[rightsideArrayIndex++];
		}
	}

	if (mid < leftsideArrayIndex) {
		for (int i = rightsideArrayIndex; i <= high; i++) {
			sorted[sortedArrayIndex++] = card[i];
		}
	}
	else {
		for (int i = leftsideArrayIndex; i <= mid; i++) {
			sorted[sortedArrayIndex++] = card[i];
		}
	}

	for (int i = low; i <= high; i++) {
		card[i] = sorted[i];
	}
}

void merge_sort(int low, int high) {
	int mid = (low + high) / 2;

	if (low < high) {
		merge_sort(low, mid);
		merge_sort(mid + 1, high);
		merge(low, mid, high);
	}
}

int binary_search(int N, int key) {
	int low = 0, high = N, mid = 0;

	while (low <= high) {
		mid = (low + high) / 2;
		if (sorted[mid] == key) {
			return 1;
		}
		else if (sorted[mid] < key) {
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}
	return 0;
}