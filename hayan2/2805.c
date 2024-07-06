#define _CRT_SECURE_NO_WARNINGS
#define MAX(a, b) a > b ? a : b
#define ull unsigned long long
#define ARRAY_LEN 1000001
#define LIMIT 2000000001
#include <stdio.h>
#include <stdlib.h>

ull tree[ARRAY_LEN];

int parameterSearch(int N, int M, ull x);

int main(void) {
	ull max = 0;
	int N, M;

	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		scanf("%lld", &tree[i]);
		max = MAX(max, tree[i]);
	}

	printf("%d", parameterSearch(N, M, max));

	return 0;
}

int parameterSearch(int N, int M, ull x) {
	ull low = 0, high = x, mid, sum = 0, ret = 0;

	while (low <= high) {
		mid = (low + high) / 2;
		sum = 0;

		for (int i = 0; i < N; i++) {
			if (mid <= tree[i]) {
				sum += (tree[i] - mid);
			}

			if (LIMIT <= sum) {
				break;
			}
		}

		if (sum < M) {
			high = mid - 1;
		}
		else {
			low = mid + 1;

			ret = MAX(ret, mid);
		}
	}

	return ret;
}