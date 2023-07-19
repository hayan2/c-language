#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int cards[1001] = { 0, };
	int dp[1001] = { 0, };
	int N;

	scnaf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", cards[i]);
	}

	

	return 0;
}	