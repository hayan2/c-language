#define _CRT_SECURE_NO_WARNINGS
#define MAX_SIZE 100001
#define CHAR_LEN 101
#include <stdio.h>
#include <string.h>

int age[MAX_SIZE];
char name[MAX_SIZE][CHAR_LEN];
int sortedAge[MAX_SIZE];
char sortedName[MAX_SIZE][CHAR_LEN];

void merge(int start, int mid, int end);
void merge_sort(int start, int end);

int main(void) {
	int n;

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d %s", &age[i], name[i]);
	}

	merge_sort(0, n - 1);

	for (int i = 0; i < n; i++) {
		printf("%d %s\n", sortedAge[i], sortedName[i]);
	}

	return 0;
}

void merge(int start, int mid, int end) {
	int leftsideArrayIndex, rightsideArrayIndex, sortedArrayIndex;
	leftsideArrayIndex = start;
	rightsideArrayIndex = mid + 1;
	sortedArrayIndex = start;

	while (leftsideArrayIndex <= mid && rightsideArrayIndex <= end) {
		if (age[leftsideArrayIndex] <= age[rightsideArrayIndex]) {
			sortedAge[sortedArrayIndex] = age[leftsideArrayIndex];
			strcpy(sortedName[sortedArrayIndex++], name[leftsideArrayIndex++]);
		}
		else {
			sortedAge[sortedArrayIndex] = age[rightsideArrayIndex];
			strcpy(sortedName[sortedArrayIndex++], name[rightsideArrayIndex++]);
		}
	}

	if (mid < leftsideArrayIndex) {
		for (int i = rightsideArrayIndex; i <= end; i++) {
			sortedAge[sortedArrayIndex] = age[i];
			strcpy(sortedName[sortedArrayIndex++], name[i]);
		}
	}
	else {
		for (int i = leftsideArrayIndex; i <= mid; i++) {
			sortedAge[sortedArrayIndex] = age[i];
			strcpy(sortedName[sortedArrayIndex++], name[i]);
		}
	}

	for (int i = start; i <= end; i++) {
		age[i] = sortedAge[i];
		strcpy(name[i], sortedName[i]);
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