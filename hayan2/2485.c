#define _CRT_SECURE_NO_WARNINGS
#define ARRAY_SIZE 100001
#include <stdio.h>

int get_gcd(int a, int b) {
	return b ? get_gcd(b, a % b) : a;
}

int main(void) {
	int trees[ARRAY_SIZE];
	int distance[ARRAY_SIZE];
	int N;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &trees[i]);
		if (i != 0) {
			distance[i - 1] = trees[i] - trees[i - 1];
		}
	}

	int gcdDistance = distance[0];

	for (int i = 1; i < N - 1; i++) {
		gcdDistance = get_gcd(distance[i], gcdDistance);
	}

	int count = 0, check = trees[0];

	for (int i = 0; i < N; i++) {
		while (trees[i] != check) {
			count++;
			check += gcdDistance;
		}
		check += gcdDistance;
	}
	
	printf("%d", count);

	return 0;
}