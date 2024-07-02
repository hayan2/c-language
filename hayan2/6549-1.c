#define _CRT_SECURE_NO_WARNINGS
#define ARRAY_LEN 100034
#define ull unsigned long long
#define MAX(a, b) a > b ? a : b
#define MIN(a, b) a > b ? b : a
#include <stdio.h>

ull hist[ARRAY_LEN] = { 0, };

ull getResult(ull low, ull high);

// wrong
int main(void) {
	ull N;

	while (scanf("%lld", &N), N != 0) {
		hist[0] = hist[N + 1] = 0;
		for (int i = 1; i <= N; i++) {
			scanf("%lld", &hist[i]);
		}

		ull res = getResult(0, N + 1);
		printf("%lld\n", res);
	}

	return 0;
}

ull getResult(ull low, ull high) {
	ull mid = (low + high) / 2;
	ull midL = mid - 1, midH = mid + 1;
	ull midArea = hist[mid], height = hist[mid];

	if (low + 1 >= high) {
		return midArea * 1;
	}

	while (midL > low || midH < high) {
		if (midL >= low && hist[midL] <= hist[midL - 1]) {
			height = MIN(height, hist[midL - 1]);
			midL--;
		}
		if (midH <= high && hist[midH] <= hist[midH + 1]) {
			height = MIN(height, hist[midH + 1]);
			midH++;
		}
		
		ull width = midH - midL - 1;
		midArea = MAX(midArea, width * height);
	}

	return MAX(midArea, MAX(getResult(low, mid), getResult(mid, high)));
}