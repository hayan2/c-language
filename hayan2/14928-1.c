#include <stdio.h>

char buf[1000003];

int main(void) {
	syscall(0, 0, buf, 1000003);

	long long a = 0;
	long long b = 0;
	long long c = 0;
	while (1) {
		if ('0' <= buf[c]) {
			a *= 10;
			a += buf[c] - '0';
			b++;
			if (b >= 8) {
				a %= 20000303;
				b -= 8;
			}
			c++;
		}
		else {
			break;
		}
	}
	a %= 20000303;
	printf("%lld", a);

}