#define _CRT_SECURE_NO_WARNINGS
#define ARRAY_LEN 100023
#define ull unsigned long long
#define MAX(a, b) a > b ? a : b
#define MIN(a, b) a > b ? b : a
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
	ull mid = (low + high) / 2;
	ull L, R, M;

	if (low > high)
		return 0LL;

	if (low == high)
		return hist[mid];

	L = sol(low, mid);
	R = sol(mid + 1, high);
	M = getResult(low, high, mid);

	if (L > R && L > M) 
		return L;	
	if (R > L && R > M) 
		return R;
	return M;
}

ull getResult(ull low, ull high, ull mid) {
	ull midLow = mid, midHigh = mid;
	ull area = hist[mid], height = hist[mid];

	while (midLow > low || midHigh < high) {
		if (midHigh < high && (midLow == low || hist[midLow - 1] < hist[midHigh + 1])) {
			midHigh++;
			height = MIN(height, hist[midHigh]);
		}
		else {
			midLow--;
			height = MIN(height, hist[midLow]);
		}
		ull width = midHigh - midLow + 1;
		area = MAX(area, width * height);
	}

	return area;
}