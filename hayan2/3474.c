#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main(void) {
	int T, N;	

	scanf("%d", &T);

	for (int i = 0; i < T; i++) {
		long long result = 0;
		scanf("%d", &N);
		for (int j = 5; j <= N; j *= 5) {
			result += (N / j);
		}
		printf("%d\n", result);
	}

	return 0;
}