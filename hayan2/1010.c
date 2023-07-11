#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int T;
	int n, m;
	long long int result[32][32] = { 0, };

	scanf("%d", &T);

	for (int i = 0; i < T; i++) {
		scanf("%d %d", &n, &m);
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (i == j) {
					result[i][j] = 1;
					continue;
				}
				if (j - i == 1) {
					result[i][j] = j;
					continue;
				}
				if (i == 1) {
					result[i][j] = j;
					continue;
				}
				result[i][j] = result[i][j - 1] + result[i - 1][j - 1];
			}
		}

		printf("%d\n", result[n][m]);
	}

	return 0;
}