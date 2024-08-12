#define _CRT_SECURE_NO_WARNINGS
#define MAX(a, b) a > b ? a : b
#define ARRAY_LEN 101
#include <stdio.h>
#include <stdlib.h>

typedef struct App {
	int memory;
	int cost;
}App;

int main(void) {
	int cache[ARRAY_LEN * ARRAY_LEN] = { 0, };
	int N, M, costSum = 0, flag = 0;

	scanf("%d %d", &N, &M);

	App* app = (App*)malloc(sizeof(App) * N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &app[i].memory);
	}

	for (int i = 0; i < N; i++) {
		scanf("%d", &app[i].cost);
		costSum += app[i].cost;
	}

	for (int i = 0; i < N; i++) {
		for (int j = costSum; j >= 0; j--) {
			if (j < app[i].cost) {
				break;
			}
			cache[j] = MAX(cache[j], cache[j - app[i].cost] + app[i].memory);

			// printf("%d : %d | ", j, cache[j]);
		}
		// printf("\n");
	}

	for (int i = 0; i < ARRAY_LEN * ARRAY_LEN; i++) {
		if (cache[i] >= M) {
			printf("%d", i);
			break;
		}
	}

	return 0;
}