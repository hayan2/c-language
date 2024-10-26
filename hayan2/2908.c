#define _CRT_SECURE_NO_WARNINGS
#define MAX(a, b) (a > b) ? a : b
#include <stdio.h>
#include <string.h>

int main(void) {
	char a[4], b[4];
	int getA = 0, getB = 0, result = 0;

	scanf("%s %s", a, b);	
	
	getA = ((a[2] - 48) * 100) + ((a[1] - 48) * 10) + (a[0] - 48);
	getB = ((b[2] - 48) * 100) + ((b[1] - 48) * 10) + (b[0] - 48);

	result = MAX(getA, getB);

	printf("%d", result);

	return 0;
}