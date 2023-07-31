#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int bigger(int a, int b) {
	if (a > b) {
		return a;
	}
	return b;
}

int main(void) {
	int arr[1001] = { 0, };
	int dp_left[1001], dp_right[1001]; 
	int N;

	scanf("%d", &N);


	for (int i = 0; i < N; dp_left[i++] = 1);
	for (int i = 0; i < N; dp_right[i++] = 1);

	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	for (int i = 0; i < N; i++) {
		for (int j = i - 1; j >= 0; j--) {
			if ((arr[j] < arr[i]) && (dp_left[i] < dp_left[j] + 1)) {
				dp_left[i] = dp_left[j] + 1;
			}
		}
	}
	for (int i = N - 1; i >= 0; i--) {
		for (int j = i + 1; j < N; j++) {
			if ((arr[j] < arr[i]) && (dp_right[i] < dp_right[j] + 1)) {
				dp_right[i] = dp_right[j] + 1;
			}
		}
	}

	int result = 0;
	for (int i = 0; i < N; i++) {
		result = bigger(result, (dp_left[i] + dp_right[i]));
	}

	printf("%d", result - 1);

	return 0;
}