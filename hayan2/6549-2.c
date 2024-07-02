#define _CRT_SECURE_NO_WARNINGS
#define ull unsigned long long 
#define MAX(a, b) a > b ? a : b
#define MIN(a, b) a > b ? b : a
#define ARRAY_LEN 100021
#include <stdio.h>

ull hist[ARRAY_LEN] = { 0, };

ull sol(ull low, ull high);
ull getResult(ull low, ull high, ull mid);

int main(void) {
	ull N;

	while (scanf("%lld", &N), N != 0) {
		for (int i = 1; i <= N; i++) {
			scanf("%lld", &hist[i]);
		}

		ull res = sol(1, N);

		printf("%lld\n", res);
	}

	return 0;
}

ull sol(ull low, ull high) {
	if (low > high) {
		return 0LL;
	}
	if (low == high) {
		return hist[low];
	}

	ull L = 0, R = 0, M = 0;
	ull mid = (low + high) / 2;

	L = sol(low, mid);
	R = sol(mid + 1, high);
	M = getResult(low, high, mid);

	if (L > R && L > M) {
		return L;
	}
	if (R > L && R > M) {
		return R;
	}
	if (M > L && M > R) {
		return M;
	}
	return M;
}

ull getResult(ull low, ull high, ull mid) {
	ull midL = mid, midH = mid, height = hist[mid];
	ull area = hist[mid];

	while (midL > low || midH < high) {
		if (midH < high && (midL == low || hist[midL - 1] < hist[midH + 1])) {
			midH++;
			height = MIN(height, hist[midH]);
		}
		else {
			midL--;
			height = MIN(height, hist[midL]);
		}

		ull width = (ull)midH - (ull)midL + 1;
		area = MAX(area, width * (ull)height);
	}

	return area;
}