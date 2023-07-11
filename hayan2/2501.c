#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void) {	
	int n, k;	

	scanf("%d %d", &n, &k);	

	int* arr = (int*)calloc(n, sizeof(int));

	int idx = 1;

	for (int i = 1; i <= n; i++) {
		if (n % i == 0) {
			arr[idx++] = i;			
		}
	}

	printf("%d", arr[k]);

	return 0;
}