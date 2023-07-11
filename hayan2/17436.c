#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int _popCnt(int b) {
	int cnt = 0;
	while (b) {
		b = b & (b - 1);
		cnt++;
	}
	return cnt;
}

int main(void) {
	int N;
	long long M, ans = 0;

	scanf("%d %lld", &N, &M);

	int* primeNum = (int*)calloc(N, sizeof(int));

	for (int i = 0; i < N; i++) {
		scanf("%d", &primeNum[i]);
	}	
	
	for (int i = 1; i < (1 << N); i++) {
		int popCnt = _popCnt(i);
		long long x = 1;

		for (int j = 0; j < N; j++) {
			if (i & (1 << j)) {
				x *= primeNum[j]; 
			}
		}

		if (popCnt % 2 == 1) {
			ans += (M / x);
		}
		else {
			ans -= (M / x);
		}
	}

	printf("%lld", ans);

	return 0;
}