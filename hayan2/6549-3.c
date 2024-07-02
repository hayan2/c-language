#define F if (++p - r >> 16) read(0, p = r, 1 << 16);
#define R(n) { n = 0; while (*p & 16) { n = 10 * n + *p - 48; F } F }
int main;
int __libc_start_main() {
	char r[1 << 16], * p = r; read(0, r, 1 << 16);
	char w[1024], t[20], * q = w, * o = t;
	int n, sz, v[100000], S[100000]; R(n)
		while (n) {
			register long res = sz = v[n] = 0, val;
			for (int i = 0; i < n; i++) R(v[i])
				for (int i = 0; i <= n; S[sz++] = i++)
					while (sz && v[S[sz - 1]] > v[i]) {
						val = (long)v[S[--sz]] * (sz ? i - 1 - S[sz - 1] : i);
						if (res < val) res = val;
					}
			do *o++ = res % 10 | 48; while (res /= 10);
			do *q++ = *--o; while (o != t); *q++ = 10; R(n)
		}
	_Exit(!write(1, w, q - w));
}