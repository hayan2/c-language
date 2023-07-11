#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int total_price;
	int n, result = 0;
	int a, b;

	scanf("%d", &total_price);
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d %d", &a, &b);

		result += (a * b);
	}

	if (total_price == result) {
		printf("Yes");
	}
	else {
		printf("No");
	}

	return 0;
}