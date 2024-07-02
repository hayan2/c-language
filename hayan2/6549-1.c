#define _CRT_SECURE_NO_WARNINGS
#define ARRAY_LEN 100034
#define ull unsigned long long
#define MAX(a, b) a > b ? a : b
#define MIN(a, b) a > b ? b : a
#include <stdio.h>

int cnt = 0;

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
	printf("cnt : %d\n", cnt++);
	printf("low : %lld high : %lld\n", low, high);
	ull mid = (low + high) / 2;
	ull midL = mid, midH = mid;
	ull midArea = hist[mid], height = hist[mid];
	ull width;

	if (low + 1 >= high) {
		return midArea * 1;
	}

	while (midL >= low) {
		height = MIN(height, hist[midL]);
		width = midH - midL + 1;
		midArea = MAX(midArea, width * height);
		midL--;
	}

	while (midH <= high) {
		height = MIN(height, hist[midH]);
		width = midH - midL + 1;
		midArea = MAX(midArea, width * height);

		midH++;
	}

	return MAX(midArea, MAX(getResult(low, mid - 1), getResult(mid + 1, high)));
}