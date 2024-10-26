#define _CRT_SECURE_NO_WARNINGS
#define MAX(a, b) a > b ? a : b
#define ull unsigned long long
#define ARRAY_LEN 200001
#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
	const int* A = a, * B = b;

	return (*A > *B) - (*A < *B);
}

int parameterSearch(int N, int C, int x);

int arr[ARRAY_LEN];

int main(void) {
	int N;
	int C;

	scanf("%d %d", &N, &C);

	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	qsort(arr, N, sizeof(int), compare);

	int res = parameterSearch(N, C, arr[N - 1]);

	printf("%d", res);
	 
	return 0;
}

int parameterSearch(int N, int C, int x) {
	int low = 1, high = x - arr[0], mid, est, dis = 0, cnt, ret = 0;

	while (low <= high) {
		mid = (low + high) / 2;	
		est = arr[0];		
		cnt = 1;

		for (int i = 1; i < N; i++) {
			dis = arr[i] - est;

			if (dis >= mid) {
				cnt++;
				est = arr[i];
			}
		}

		if (cnt < C) {
			high = mid - 1;
		}
		else {
			low = mid + 1;

			ret = mid;
		}
	}	

	return ret;
}