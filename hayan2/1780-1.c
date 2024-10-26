#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int cnt[2];
char p[2187][2187];
char rbuf[1 << 20];

char getbyte_1780() {
	static int ri = 1 << 20;
	if (ri == 1 << 20) {
		fread(rbuf, 1, 1 << 20, stdin);
		ri = 0;
	}
	
	return rbuf[ri++];
}

int getint_1780() {
	char c;
	while ((c = getbyte_1780()) != '0' && c != '1' && c != '-');
	if (c == '-') return '0' - getbyte_1780();
	return c - '0';
}

void recur(int x, int y, int sz) {
	int i, j, ok = 1;

	for (i = y; i < y + sz && ok; i++) {
		for (j = x; j < x + sz && ok; j++) {
			if (p[i][j] != p[y][x]) ok = 0;
		}
	}
	if (ok) cnt[p[y][x] + 1]++;
	else {
		for (i = y; i < y + sz; i += sz / 3) {
			for (j = x; j < x + sz; j += sz / 3) {
				recur(j, i, sz / 3);
			}
		}
	}
}

int main() {
	int i, j, n;

	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			p[i][j] = getint_1780();
		}
	}
	recur(0, 0, n);
	printf("%d\n%d\n%d\n", cnt[0], cnt[1], cnt[2]);

}