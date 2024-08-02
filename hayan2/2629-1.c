#define _CRT_SECURE_NO_WARNINGS
#define MAX(a, b) a > b ? a : b
#define MAX_WEIGHT 40001
#define WEIGHT_LEN 31
#define MARBLE_LEN 8
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 30 * 40000
bool cache[WEIGHT_LEN][MAX_WEIGHT];
// cache[weight index][can measure]
int weight[WEIGHT_LEN];
int marble[MARBLE_LEN];
int w, m;

void sol() {	
	int lim = -12357723;
	for (int i = 1; i <= w; i++) {
		cache[i][weight[i]] = true;
		lim = MAX(lim, weight[i]);

		for (int j = 0; j < MAX_WEIGHT; j++) {
			if (j > lim) {
				break;
			}

			if (!cache[i - 1][j]) {
				continue;
			}
			
			// >
			cache[i][j] = true;
			// +
			cache[i][j + weight[i]] = true;
			// -
			cache[i][abs(j - weight[i])] = true;

			lim = MAX(lim, j + weight[i]);
		}
	}

	for (int i = 0; i < m; i++) {
		printf("%c ", cache[w][marble[i]] ? 'Y' : 'N');
	}
}

int main(void) {
	scanf("%d", &w);

	for (int i = 1; i <= w; i++) {
		scanf("%d", &weight[i]);
	}

	scanf("%d", &m);

	for (int i = 0; i < m; i++) {
		scanf("%d", &marble[i]);
	}

	memset(cache, false, sizeof(cache));

	sol();

	return 0;
}