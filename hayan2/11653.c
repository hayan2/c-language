#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int arr[100001] = { 0, };	
	int n, m, check = 1, idx = 0;
	
	scanf("%d", &n);
	m = n;
	for (int i = 2; i <= n; i++) {
		if (n % i == 0) {
			n /= i;
			arr[idx++] = i;
			check *= i;
			i = 1;
		}

		if (check == m) {
			for (int i = 0; i < idx; i++) {
				printf("%d\n", arr[i]);
			}
			break;
		}
	}

	return 0;
}