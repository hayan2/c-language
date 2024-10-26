#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int arr[10001];
	int n, a, x, length = 0;
	
	scanf("%d %d", &n, &x);

	for (int i = 0; i < n; i++) {
		scanf("%d", &a);
		if (a < x) {
			arr[length++] = a;			
		}
	}

	for (int i = 0; i < length; i++) {
		printf("%d ", arr[i]);
	}	

	return 0;
}