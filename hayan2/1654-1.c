#define _CRT_SECURE_NO_WARNINGS
#define ull unsigned long long
#define ARRAY_LEN 10001
#define MAX(a, b) a > b ? a : b
#define MIN(a, b) a > b ? b : a
#include <stdio.h>

ull lan[ARRAY_LEN];

ull parameterSearch(int K, int N, ull x);

int main(void) {
	ull max = 0;
	int K, N;

	scanf("%d %d", &K, &N);

	for (int i = 0; i < K; i++) {
		scanf("%lld", &lan[i]);
		max = MAX(max, lan[i]);
	}

	ull res = parameterSearch(K, N, max);

	printf("%lld", res);

	return 0;
}

ull parameterSearch(int K, int N, ull x) {
	ull low = 1, high = x, mid;
	ull res = 0, cnt = 0;

	while (low <= high) {
		mid = (low + high) / 2;
		cnt = 0;

		for (int i = 0; i < K; i++) {
			cnt += (lan[i] / mid);
		}

		if (N > cnt) {
			high = mid - 1;
		}
		else {
			low = mid + 1;

			res = MAX(res, mid);
		}
	}

	return res;
}