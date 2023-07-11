#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
	int N, b, c;
	long long result = 0;

	scanf("%d", &N);

	int* testTaker = (int*)calloc(N, sizeof(int));

	for (int i = 0; i < N; i++) {
		scanf("%d", &testTaker[i]);
	}

	scanf("%d %d", &b, &c);

	for (int i = 0; i < N; i++) {
		result++;
		testTaker[i] -= b;

		if (testTaker[i] > 0) {
			result += ceil(testTaker[i] * 1.0 / c);
		}
	}

	printf("%lld", result);	

	return 0;
}