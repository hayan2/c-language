#define _CRT_SECURE_NO_WARNINGS
#define ARRAY_SIZE 101
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	char sentence[ARRAY_SIZE];
	char dp[ARRAY_SIZE];

	while (1) {
		int count = 0;
		gets(sentence);
		if (sentence[0] == '.' && strlen(sentence) == 1) {
			exit(0);
		}
		
		for (int i = 0; i < strlen(sentence); i++) {
			if (sentence[i] == '(') {
				dp[count++] = '(';
			}
			else if (sentence[i] == '[') {
				dp[count++] = '[';
			}
			else if (sentence[i] == ')') {
				if (dp[count - 1] == '(') {
					count--;
				}
				else {
					count = -8407;
					break;
				}
			}
			else if (sentence[i] == ']') {
				if (dp[count - 1] == '[') {
					count--;
				}
				else {
					count = -422;
					break;
				}
			}
		}

		if (count == 0) {
			printf("yes\n");
		}
		else {
			printf("no\n");
		}
	}

	return 0;
}