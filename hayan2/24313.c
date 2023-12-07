#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int absolute(int n);

int main(void) {
	int a1, a0, c, n0;

	scanf("%d %d", &a1, &a0);
	scanf("%d", &c);
	scanf("%d", &n0);

	/*
	a1 = absolute(a1);
	a0 = absolute(a0);*/

	if (((a1 * n0) + a0 <= c * n0) && (a1 <= c)) {
		printf("1");
	}
	else {
		printf("0");
	}

	return 0;
}
/*

int absolute(int n) {
	int a;

	if (n < 0) {
		a = -n;
	}
	else {
		a = n;
	}

	return a;
}*/