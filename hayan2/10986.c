#define _CRT_SECURE_NO_WARNINGS
#define ARRAY_LEN 1000001
#include <stdio.h>
#include <stdlib.h>

int A[ARRAY_LEN];
long long S[ARRAY_LEN];

int main(void) {
	int N, M, quotCnt = 0;
	long long res = 0;

	scanf("%d %d", &N, &M);
	
	for (int i = 1; i <= N; i++) {
		scanf("%d", &A[i]);
		if ((S[i - 1] + A[i]) % M == 0) {
			quotCnt++;
			res += quotCnt;
		}
		S[i] = (S[i - 1] + A[i]) % M;
	}

	for (int i = 1; i < M; i++) {
		int cnt = 0;
		for (int j = 1; j <= N; j++) {
			if (i == S[j]) {
				res += cnt;
				cnt++;
			}
		}
	}

	printf("%lld", res);

 	return 0;
}