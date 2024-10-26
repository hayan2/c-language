#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int check_units(int n);

int main(void) {
	int n, res = 0, result = 0;

	scanf("%d", &n);		
	
	for (int i = n / 2; i < n; i++) {
		int mod = check_units(i);
		res += i;
		int n1 = i;
		while (mod >= 1 && mod != 0) {
			res += (n1 / mod);
			n1 %= mod;
			mod /= 10;
		}

		if (res == n) {	
			result = i;
			break;
		}
		res = 0;
	}

	printf("%d", result);

	return 0;
}

int check_units(int n) {
	int mod = 1000000, flag = n;

	while (flag == n && mod != 0) {
		n %= mod;
		mod /= 10;
	}

	if (mod == 0) {
		return 10;
	}
	else {
		return mod * 10;
	}	
}