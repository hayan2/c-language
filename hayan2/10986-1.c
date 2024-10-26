#define _CRT_SECURE_NO_WARNINGS
#define ARRAY_LEN 1001
#include <stdio.h>

int main(void) {
	long long S[ARRAY_LEN] = { 0, };
	long long res = 0, x = 0;
	int N, M, A;

	scanf("%d %d", &N, &M);
		
	for (int i = 0; i < N; i++) {		
		scanf("%d", &A);
		x += A;
		S[x % M]++;
		if (x % M == 0) {
			res++;
		}
	}

	for (int i = 0; i < M; i++) {
		if (S[i] < 2) {
			continue;
		}
		res += (S[i] * (S[i] - 1) / 2);
	}

	printf("%lld", res);

	return 0;
}