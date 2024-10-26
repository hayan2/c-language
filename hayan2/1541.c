#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	char c;
	int i = 0, N, x;
	
	for (scanf("%d", &N); scanf("%c", &c), c != 10;) {
		if (c == '-') {
			i = 1;
		}
		scanf("%d", &x);

		if (i) {
			N -= x;
		}
		else {
			N += x;
		}
	}

	printf("%d\n", N);	

	return 0;
}