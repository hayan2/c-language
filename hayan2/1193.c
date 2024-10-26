#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int x, idx = 1, i = 1, j = 1;
	// j++ -> 0, i++ -> 1
	int checkInc = 0;

	scanf("%d", &x);

	while (x != idx++) {
		if (checkInc == 0) {
			if (i == 1) {
				j++;
				checkInc = 1;
			}
			else {
				i--;
				j++;
			}			
		}
		else {
			if (j == 1) {
				i++;
				checkInc = 0;
			}
			else {
				j--;
				i++;
			}			
		}
	}

	printf("%d/%d", i, j);

	return 0;
}