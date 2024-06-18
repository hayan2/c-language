#define _CRT_SECURE_NO_WARNINGS
#define MIN(a, b) a > b ? b : a
#define ARRAY_LEN 100001
#include <stdio.h>

int road[ARRAY_LEN] = { 0, };
int price[ARRAY_LEN] = { 0, };

int main(void) {
	int N, currentIdx = 1;
	long long distanceSum, res = 0;

	scanf("%d", &N);

	for (int i = 1; i < N; i++) {
		scanf("%d", &road[i]);
	}

	for (int i = 1; i < N + 1; i++) {
		scanf("%d", &price[i]);
	}

	distanceSum = road[1];

	for (int i = 2; i < N + 1; i++) {		
		if (price[currentIdx] > price[i]) {
			res += distanceSum * price[currentIdx];
			currentIdx = i;
			distanceSum = road[i];
		}
		else {
			distanceSum += road[i];
		}
	}

	if (distanceSum != 0) {
		res += distanceSum * price[currentIdx];
	}

	printf("%lld", res);

	return 0;
}