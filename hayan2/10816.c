#define _CRT_SECURE_NO_WARNINGS
#define ARRAY_LEN 20000001
#define MOD 10000001
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long int target[ARRAY_LEN];
int card[ARRAY_LEN];

int main(void) {
	int N, M;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		long long int num;
		scanf("%lld", &num);
		card[num + MOD]++;
	}

	scanf("%d", &M);

	for (int i = 0; i < M; i++) {
		scanf("%lld", &target[i]);
	}

	for (int i = 0; i < M; i++) {
		printf("%d ", card[target[i] + MOD]);
	}

	return 0;
}