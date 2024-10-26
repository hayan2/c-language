#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct WORD {
	char word[11];
	int count;
	int len;
}WORD;

int compare(WORD* a, WORD* b, int flag) {
	int idx = 0;

	if (flag) {
		if (a->len > b->len)
			return 1;
		else if (a->len < b->len)
			return 0;

		while (a->word[idx]) {
			if (a->word[idx] < b->word[idx])
				return 1;
			else if (a->word[idx] > b->word[idx])
				return 0;

			idx++;
		}
		return 1;
	}

	if (a->count >= b->count)
		return 1;

	return 0;
}

void mergeSort(WORD words[], WORD sorted[], int start, int mid, int end, int flag) {
	int leftIndex, rightIndex, sortedIndex;
	leftIndex = start;
	rightIndex = mid + 1;
	sortedIndex = start;

	while (leftIndex <= mid && rightIndex <= end) {
		if (compare(&words[leftIndex], &words[rightIndex], flag))
			sorted[sortedIndex++] = words[leftIndex++];
		else
			sorted[sortedIndex++] = words[rightIndex++];
	}

	if (mid < leftIndex) {
		for (int i = rightIndex; i <= end; i++)
			sorted[sortedIndex++] = words[i];
	}
	else {
		for (int i = leftIndex; i <= mid; i++)
			sorted[sortedIndex++] = words[i];
	}

	for (int i = start; i <= end; i++)
		words[i] = sorted[i];

	return;
}

void merge(WORD words[], WORD sorted[], int start, int end, int flag) {
	if (start < end) {
		int mid = (start + end) / 2;
		merge(words, sorted, start, mid, flag);
		merge(words, sorted, mid + 1, end, flag);
		mergeSort(words, sorted, start, mid, end, flag);
	}
	return;
}

int main(void) {
	int N, M, idx = 0;

	scanf("%d %d", &N, &M);

	char* input = (char*)malloc(N);
	WORD* words = (WORD*)malloc(sizeof(WORD) * N);
	WORD* sorted = (WORD*)malloc(sizeof(WORD) * N);

	if (words == NULL || sorted == NULL)
		exit(1);

	for (int i = 0; i < N; i++) {
		scanf("%s", input);

		if (strlen(input) >= M) {
			strcpy(words[idx].word, input);
			words[idx].len = strlen(input);
			words[idx++].count++;
		}
	}

	if (N == 1) {
		if (strlen(input) >= M) {
			printf("%s", input);
		}
		exit(0);
	}

	merge(words, sorted, 0, N - 1, 1);

	int i = 0, next = 1, sortedIndex = 0;

	while (i < idx) {
		if (strcmp(sorted[i].word, sorted[next].word)) {
			words[sortedIndex++] = sorted[i];
			i = next;
			next = i + 1;
			continue;
		}
		else
			sorted[i].count++;
		next++;
	}

	merge(words, sorted, 0, sortedIndex - 1, 0);

	for (int i = 0; i < sortedIndex; i++)
		printf("%s\n", words[i].word);

	return 0;
}