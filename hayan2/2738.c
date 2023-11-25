#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int a[101][101];
	int b[101][101];

	int n, m;

	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &a[i][j]);
		}	
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &b[i][j]);			
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%d ", a[i][j] + b[i][j]);
		}
		printf("\n");
	}

	return 0;
}