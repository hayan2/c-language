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

	if (n == 1) {
		printf("%s", arr[0]);
		return 0;
	}

	merge_sort(0, n - 1);
	
	// strcmp true = 0
	for (int i = 0; i < n; i++) {
		char duplicated[CHAR_LEN];
		if (strcmp(duplicated, sorted[i]) == 0) {
			continue;
		}
		else {
			printf("%s\n", sorted[i]);
			strcpy(duplicated, sorted[i]);
		}
	}

	return 0;
}

void merge(int start, int mid, int end) {
	int leftsideArrayIndex, rightsideArrayIndex, sortedArrayIndex;
	leftsideArrayIndex = start;
	rightsideArrayIndex = mid + 1;
	sortedArrayIndex = start;

	while (leftsideArrayIndex <= mid && rightsideArrayIndex <= end) {
		if (strlen(arr[leftsideArrayIndex]) < strlen(arr[rightsideArrayIndex])) {
			strcpy(sorted[sortedArrayIndex++], arr[leftsideArrayIndex++]);
		}	
		else if (strlen(arr[leftsideArrayIndex]) == strlen(arr[rightsideArrayIndex])) {
			for (int i = 0; i < strlen(arr[leftsideArrayIndex]); i++) {
				if (arr[leftsideArrayIndex][i] < arr[rightsideArrayIndex][i]) {
					strcpy(sorted[sortedArrayIndex++], arr[leftsideArrayIndex++]);
					break;
				}
				else if (arr[leftsideArrayIndex][i] > arr[rightsideArrayIndex][i]) {
					strcpy(sorted[sortedArrayIndex++], arr[rightsideArrayIndex++]);
					break;
				}

				if (strlen(arr[leftsideArrayIndex]) - 1 == i) {
					strcpy(sorted[sortedArrayIndex++], arr[rightsideArrayIndex++]);
				}
			}
		}
		else {
			strcpy(sorted[sortedArrayIndex++], arr[rightsideArrayIndex++]);
		}
	}

	if (mid < leftsideArrayIndex) {
		for (int i = rightsideArrayIndex; i <= end; i++) {
			strcpy(sorted[sortedArrayIndex++], arr[i]);
		}
	}
	else {
		for (int i = leftsideArrayIndex; i <= mid; i++) {
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