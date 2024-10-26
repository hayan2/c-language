#define _CRT_SECURE_NO_WARNINGS
#define MAX(a, b) (a > b) ? a : b
#define UPPERMOD 65
#define LOWERMOD 97
#define CNTLEN 27
#include <stdio.h>

int main(void) {
	char arr[1000001];
	int cnt[27] = { 0, };

	gets(arr);

	int len = strlen(arr);

	// A - Z 65 - 90 , a - z 97 - 122
	for (int i = 0; i < len; i++) {
		if (arr[i] == 'a' || arr[i] == 'A') {
			cnt[1]++;
		}
		else if (arr[i] == 'b' || arr[i] == 'B') {
			cnt[2]++;
		}
		else if (arr[i] == 'c' || arr[i] == 'C') {
			cnt[3]++;
		}
		else if (arr[i] == 'd' || arr[i] == 'D') {
			cnt[4]++;
		}
		else if (arr[i] == 'e' || arr[i] == 'E') {
			cnt[5]++;
		}
		else if (arr[i] == 'f' || arr[i] == 'F') {
			cnt[6]++;
		}
		else if (arr[i] == 'g' || arr[i] == 'G') {
			cnt[7]++;
		}
		else if (arr[i] == 'h' || arr[i] == 'H') {
			cnt[8]++;
		}
		else if (arr[i] == 'i' || arr[i] == 'I') {
			cnt[9]++;
		}
		else if (arr[i] == 'j' || arr[i] == 'J') {
			cnt[10]++;
		}
		else if (arr[i] == 'k' || arr[i] == 'K') {
			cnt[11]++;
		}
		else if (arr[i] == 'l' || arr[i] == 'L') {
			cnt[12]++;
		}
		else if (arr[i] == 'm' || arr[i] == 'M') {
			cnt[13]++;
		}
		else if (arr[i] == 'n' || arr[i] == 'N') {
			cnt[14]++;
		}
		else if (arr[i] == 'o' || arr[i] == 'O') {
			cnt[15]++;
		}
		else if (arr[i] == 'p' || arr[i] == 'P') {
			cnt[16]++;
		}
		else if (arr[i] == 'q' || arr[i] == 'Q') {
			cnt[17]++;
		}
		else if (arr[i] == 'r' || arr[i] == 'R') {
			cnt[18]++;
		}
		else if (arr[i] == 's' || arr[i] == 'S') {
			cnt[19]++;
		}
		else if (arr[i] == 't' || arr[i] == 'T') {
			cnt[20]++;
		}
		else if (arr[i] == 'u' || arr[i] == 'U') {
			cnt[21]++;
		}
		else if (arr[i] == 'v' || arr[i] == 'V') {
			cnt[22]++;
		}
		else if (arr[i] == 'w' || arr[i] == 'W') {
			cnt[23]++;
		}
		else if (arr[i] == 'x' || arr[i] == 'X') {
			cnt[24]++;
		}
		else if (arr[i] == 'y' || arr[i] == 'Y') {
			cnt[25]++;
		}
		else if (arr[i] == 'z' || arr[i] == 'Z') {
			cnt[26]++;
		}
	}

	int max = 0, result = 0;

	for (int i = 1; i < CNTLEN; i++) {		
		if (max != 0 && max == cnt[i]) {
			result = 63;			
			
		}
		if (max < cnt[i]) {
			max = cnt[i];
			result = i + 'A' - 1;
		}		
	}

	printf("%c", result);
	

	return 0;
}