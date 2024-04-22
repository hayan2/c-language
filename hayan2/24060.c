#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int A[500001];
int sorted[500001];
int count = 0, nth = 0;

void mergeSort(int low, int mid, int high, int K) {
	int left, right, sortedIndex;
	left = low;
	right = mid + 1;
	sortedIndex = low;
	
	while (left <= mid && right <= high) {
		if (A[left] < A[right]) {
			sorted[sortedIndex++] = A[left++];
			count++;
			if (count == K) {
				nth = sorted[sortedIndex - 1];
			}
		}
		else {
			sorted[sortedIndex++] = A[right++];
			count++;
			if (count == K) {
				nth = sorted[sortedIndex - 1];
			}
		}
	}

	if (mid < left) {
		for (int i = right; i <= high; i++) {
			sorted[sortedIndex++] = A[i];
			count++;
			if (count == K) {
				nth = sorted[sortedIndex - 1];
			}
		}
	}
	else {
		for (int i = left; i <= mid; i++) {
			sorted[sortedIndex++] = A[i];
			count++;
			if (count == K) {
				nth = sorted[sortedIndex - 1];
			}
		}
	}	

	for (int i = low; i <= high; i++) {
		A[i] = sorted[i];
	}
}


void merge(int low, int high, int K) {
	int mid = (low + high) / 2;

	if (low < high) {
		merge(low, mid, K);
		merge(mid + 1, high, K);
		mergeSort(low, mid, high, K);
	}
}

int main(void) {	
	int N, K;

	scanf("%d %d", &N, &K);

	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}

	merge(0, N - 1, K);

	nth = (count > K) ? nth : -1;

	printf("%d", nth);

	return 0;
}