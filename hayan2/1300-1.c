#define _CRT_SECURE_NO_WARNINGS
#define ull unsigned long long
#define MIN(a, b) a > b ? b : a
#include <stdio.h>

ull parameterSearch(int N, int k);

int main(void) {
	ull N, k;

	scanf("%lld %lld", &N, &k);

	printf("%lld", parameterSearch(N, k));

	return 0;
}

ull parameterSearch(int N, int k) {
	ull low = 1, high = N * N, mid = 0, x;

	while (low <= high) {
		mid = (low + high) / 2;
		x = 0;

		for (int i = 1; i <= N; i++) {
			x += MIN(mid / i, N);
		}

		if (x >= k) {
			high = mid - 1;
		}
		else {
			low = mid + 1;			
		}
	}

	return low;
}