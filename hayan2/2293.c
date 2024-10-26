#define _CRT_SECURE_NO_WARNINGS
#define LIM 10001
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int cache[LIM] = { 0, };
	int N, K, coin;	

	scanf("%d %d", &N, &K);

	cache[0] = 1;
	for (int i = 0; i < N; i++) {
		scanf("%d", &coin);
		for (int j = coin; j <= K; j++) {
			cache[j] += cache[j - coin];
		}
	}

	printf("%d", cache[K]);

	return 0;
}