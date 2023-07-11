#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void) {
	int T;
	int length = 0, cnt = 0;
	char vps[51] = { NULL, };

	scanf("%d ", &T);
	// -- 40 '('  41 ')'
	for (int i = 0; i < T; i++) {
		gets(vps);
		
		length = strlen(vps);

		for (int j = 0; j < length; j++) {
			if (vps[j] == 40) {
				cnt++;
			}
			if (vps[j] == 41) {
				cnt--;
			}

			if (cnt < 0) {
				cnt = -999;
			}
		}
		if (cnt == 0) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}

		cnt = 0;
	}

	return 0;
}