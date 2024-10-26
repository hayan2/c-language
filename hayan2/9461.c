#define _CRT_SECURE_NO_WARNINGS
#define ARRAY_LEN 101
#include <stdio.h>

int main(void) {
	unsigned long long arr[ARRAY_LEN];
	int T;
	
	scanf("%d", &T);

	arr[0] = arr[1] = arr[2] = 1;

	for (int i = 3; i < ARRAY_LEN; i++) {
		arr[i] = arr[i - 2] + arr[i - 3];
	}

	while (T != 0) {
		int N;

		scanf("%d", &N);

		printf("%lld\n", arr[N - 1]);

		T--;
	}

 	return 0;
}