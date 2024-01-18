#define _CRT_SECURE_NO_WARNINGS
#define ARRAY_SIZE 101
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	while (1) {
		char sentence[ARRAY_SIZE];
		fgets(sentence, ARRAY_SIZE, stdin);
		if (sentence[0] == '.') {			
			break;
		}
		int res = 0;
		for (int i = 0; i < strlen(sentence); i++) {
			if (sentence[i] == '0') {
				break;
			}
			if (sentence[i] == '(') {
				res++;
			}
			else if (sentence[i] == ')') {
				res--;
			}
			else if (sentence[i] == '[') {
				res += 101;
			}
			else if (sentence[i] == ']') {
				res -= 101;
			}

			if (res < 0) {
				break;
			}
		}
		if (res == 0) {
			printf("YES\n");
			
		}
		else {
			printf("NO\n");
		}		
	}

	return 0;
}