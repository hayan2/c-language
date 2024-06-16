#define _CRT_SECURE_NO_WARNINGS
#define ARRAY_LEN 11
#include <stdio.h>

int main(void) {
	int A[11] = { 0, };
	int N, K, res = 0, cnt = 0;

	scanf("%d %d", &N, &K);

	res = K;

	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}

	int idx = N - 1;

	while (res != 0) {
		if (A[idx] > res) {
			idx--;
		}
		else {
			cnt += (res / A[idx]);
			res %= A[idx];
		}
	}

	printf("%d", cnt);

	return 0;
}