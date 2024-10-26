#define _CRT_SECURE_NO_WARNINGS
#define MAX(a, b) a > b ? a : b
#define ARRAY_LEN 1001
#define TWO 2
#define NUM 0
#define SEQUENCE_LEN 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	int arr[ARRAY_LEN][TWO];
	int N, result = 1;

	scanf("%d", &N);

	for (int i = 0; i < N; arr[i++][SEQUENCE_LEN] = 1) {
		scanf("%d", &arr[i][NUM]);
	}

	for (int i = 0; i < N; i++) {
		for (int j = i - 1; j >= 0; j--) {
			if ((arr[i][NUM] > arr[j][NUM]) && (arr[i][SEQUENCE_LEN] <= arr[j][SEQUENCE_LEN])) {
				arr[i][SEQUENCE_LEN] = arr[j][SEQUENCE_LEN] + 1;
				result = MAX(result, arr[i][SEQUENCE_LEN]);
			}
		}
	}	
	
	printf("%d", result);

	return 0;
}