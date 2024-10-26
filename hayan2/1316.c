#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

bool groupWordCheck(char* word);

int main(void) {
	char word[101];
	int n, result = 0;

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%s", word);

		result += groupWordCheck(word) ? 1 : 0;
	}

	printf("%d", result);

	return 0;
}

bool groupWordCheck(char* word) {
	
	int len = strlen(word);
	int cnt[27] = { 0, };

	cnt[word[0] - 96]++;

	for (int i = 1; i < len; i++) {
		// word is not equal previous array and not checked word		
		if (word[i - 1] != word[i] && cnt[word[i] - 96] != 0) {			
			return false;
		}
		cnt[word[i] - 96]++;
	}

	return true;
}