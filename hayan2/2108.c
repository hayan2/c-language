#define _CRT_SECURE_NO_WARNINGS
#define ARRAY_SIZE 500001
#define COUNT_SIZE 8001
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int arr[ARRAY_SIZE];

int compare(const void* a, const void* b) {
	const int* A = a, * B = b;

	return (*A > *B) - (*A < *B);
}

int get_mode(int* countingArray) {
	int max = 0, mode = 0, flag = 0;

	for (int i = 0; i < COUNT_SIZE; i++) {
		if (max < countingArray[i]) {
			max = countingArray[i];
		}
	}

	for (int i = 0; i < COUNT_SIZE; i++) {
		if (countingArray[i] == max) {
			if (flag == 0) {
				mode = i;
				flag++;
			}
			else if (flag == 1) {
				mode = i;
				break;
			}
		}		
	}

	return mode - 4000;
}

int main(void) {	
	int countingArray[COUNT_SIZE] = { 0, };
	int N;
	int average = 0, median = 0, mode = 0, range = 0;
	double dAverage = 0;
	
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);

		dAverage += arr[i];
		countingArray[arr[i] + 4000]++;
	}

	qsort(arr, N, sizeof(int), compare);

	average = round(dAverage / N);
	median = arr[N / 2];
	mode = get_mode(countingArray);
	range = arr[N - 1] - arr[0];

	printf("%d\n%d\n%d\n%d", average, median, mode, range);

	return 0;
}