#define _CRT_SECURE_NO_WARNINGS
#define ARRAY_LEN 1000001
#include <stdio.h>

int A[ARRAY_LEN];
int S[ARRAY_LEN];

int main(void) {	
	int N, M;

	scanf("%d %d", &N, &M);
	
	for (int i = 1; i <= N; i++) {
		scanf("%d", &A[i]);
		S[i] = S[i - 1] + A[i];
	}

 	return 0;
}