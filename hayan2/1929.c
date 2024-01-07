#define _CRT_SECURE_NO_WARNINGS
#define ARRAY_SIZE 1000001
#include <stdio.h>

int primeNumber[ARRAY_SIZE];

int main(void) {	
	int N, M;	

	scanf("%d %d", &N, &M);

	primeNumber[1] = 0;
	for (int i = 2; i < M + 1; i++) {
		primeNumber[i] = i;
	}
	
	for (int i = 2; i <= M; i++) {
		if (primeNumber[i] == 0) {
			continue;
		}
		
		for (int j = 2 * i; j <= M; j += i) {
			primeNumber[j] = 0;
		}
	}

	for (int i = N; i < M + 1; i++) {
		if (primeNumber[i] != 0) {
			printf("%d\n", primeNumber[i]);
		}
	}
 		 
	return 0;
}