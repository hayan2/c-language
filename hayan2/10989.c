#define _CRT_SECURE_NO_WARNINGS
#define MAX_SIZE 10001
#include <stdio.h>

int main(void) {
	int arr[MAX_SIZE] = { 0, };
	int n;

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		arr[x]++;
	}

	for (int i = 0; i < MAX_SIZE; i++) {
		if (0 < arr[i]) {
			for (int j = 0; j < arr[i]; j++) {	
				printf("%d\n", i);
			}
		}
	}

	return 0;
}