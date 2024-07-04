#define _CRT_SECURE_NO_WARNINGS
#define MAX(a, b) a > b ? a : b
#define MIN(a, b) a > b ? b : a
#define ull unsigned long long
#define ARRAY_LEN 10001
#define RES_LEN 2
#define RES 1
#include <stdio.h>

int res = 0, cnt = 0;

void sol(int* lan, int K, int x, int N);
int parameterSearch(int* lan, int K, ull mid, int N);

// wrong
int main(void) {
	int lan[ARRAY_LEN] = { 0, }, max = 0;
	int K, N;

	scanf("%d %d", &K, &N);

	for (int i = 0; i < K; i++) {
		scanf("%d", &lan[i]);		
		max = MAX(max, lan[i]);
	}

	sol(lan, K, max, N);

	printf("%d", res);

	return 0;
}

void sol(int* lan, int K, int x, int N) {
	ull low = 1, high = (ull)x;
	ull mid;
	
	while (low <= high) {
		mid = (low + high) / 2;
		int flag = parameterSearch(lan, K, mid, N);
			
		if (flag == 1) {
			high = mid - 1;
		}
		else if (flag == -1) {
			low = mid + 1;
		}
		else {
			res = MAX(res, mid);
			
			low = mid + 1;
		}
		if (low == high && cnt >= mid) {
			res = MAX(res, mid);
		}
	}
}

int parameterSearch(int* lan, int K, ull mid, int N) {
	cnt = 0;

	for (int i = 0; i < K; i++) {
		cnt += (lan[i] / mid);
	}

	if (N < cnt) {
		return -1;
	}
	if (N > cnt) {
		return 1;
	}
	return 0;
}