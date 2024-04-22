#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int cnt = 0;

int recursion(const char* s, int l, int r) {	
	cnt++;
	if (l >= r) 
		return 1;
	else if (s[l] != s[r])
		return 0;
	else 
		return recursion(s, l + 1, r - 1);		
}

int isPalindrome(const char* s) {
	cnt = 0;
	return recursion(s, 0, strlen(s) - 1);
}

int main() {
	char str[1001];
	int T;

	scanf("%d", &T);

	for (int i = 0; i < T; i++) {
		scanf("%s", str);
		printf("%d %d\n", isPalindrome(str), cnt);
	}
}