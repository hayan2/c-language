#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// golomb sequence
int main(void) {	
	long long result = 0;
	long long n;

	scanf("%lld", &n);
	
	int* golombArray = (int*)malloc(sizeof(int) * n);

	golombArray[1] = 1;
	result += golombArray[1]; 
	long long i;
	for (i = 2; i < (n + 1); i++) {
		golombArray[i] = 1 + golombArray[i - golombArray[golombArray[i - 1]]];
		result += golombArray[i];

		if (result >= n) {			
			break;
		}
	}	
 
	printf("%lld", i);

	return 0;
}
