#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int x, y;
	int calendar[13][32];
	
	int lastday = 0;

	for (int i = 1; i <= 12; i++) {
		calendar[i][0] = lastday;

		if (i == 2) {
			for (int j = 1; j <= 28; j++) {
				if (calendar[i][j - 1] == 7) {
					calendar[i][j] = 1;
				}
				else {
					calendar[i][j] = calendar[i][j - 1] + 1;
				}
				if (j == 28) {
					lastday = calendar[i][j];
				}
			}
		}
		else if (i == 4 || i == 6 || i == 9 || i == 11) {
			for (int j = 1; j <= 30; j++) {
				if (calendar[i][j - 1] == 7) {
					calendar[i][j] = 1;
				}
				else {
					calendar[i][j] = calendar[i][j - 1] + 1;
				}

				if (j == 30) {
					lastday = calendar[i][j];
				}
			}
		}
		else {
			for (int j = 1; j <= 31; j++) {				
				if (calendar[i][j - 1] != 7) {
					calendar[i][j] = (calendar[i][j - 1] + 1);		
				}
				else {
					calendar[i][j] = 1;
				}

				if (j == 31) {
					lastday = calendar[i][j];
				}
			}
		}
	}

	scanf("%d %d", &x, &y);

	switch (calendar[x][y]) {
	case 1:
		printf("MON");
		break;
	case 2:
		printf("TUE");
		break;
	case 3:
		printf("WED");
		break;
	case 4:
		printf("THU");
		break;
	case 5:
		printf("FRI");
		break;
	case 6:
		printf("SAT");
		break;
	case 7:
		printf("SUN");
		break;
	}

	return 0;
}