#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	while (1) {
		int arr[50001] = { 0, };
		int n, res = 0, idx = 0;
		scanf("%d", &n);
		if (n == -1) {
			break;
		}

		for (int i = 1; i < (n / 2) + 1; i++) {
			if (n % i == 0) {
				res += i;
				arr[idx++] = i;
			}
		}
		if (res == n) {
			printf("%d = ", n);
			for (int i = 0; i < idx - 1; i++) {
				printf("%d + ", arr[i]);
			}
			printf("%d\n", arr[idx - 1]);
		}
		else {
			printf("%d is NOT perfect.\n", n);
		}
	}

	return 0;
}