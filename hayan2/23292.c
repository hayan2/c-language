#define _CRT_SECURE_NO_WARNINGS
#define year1 10000000
#define y2 1000000
#define y3 100000
#define y4 10000
#define m1 1000
#define m2 100
#define d1 10
#define d2 1

#include <stdio.h>
#include <math.h>

int main(void) {
	int birth;
	int N, Y1, Y2, Y3, Y4, M1, M2, D1, D2;
	int cod;

	scanf("%d", &birth);
	scanf("%d", &N);

	Y1 = birth / year1;
	Y2 = (birth % year1) / y2;
	Y3 = (birth % y2) / y3;
	Y4 = (birth % y3) / y4;

	M1 = (birth % y4) / m1;
	M2 = (birth % m1) / m2;

	D1 = (birth % m2) / d1;
	D2 = (birth % d1) / d2;
	
	int cY1, cY2, cY3, cY4, cM1, cM2, cD1, cD2;
	int minbio = 0, minday = 99999999;

	for (int i = 1; i <= N; i++) {
		scanf("%d", &cod);

		cY1 = cod / year1;
		cY2 = (cod % year1) / y2;
		cY3 = (cod % y2) / y3;
		cY4 = (cod % y3) / y4;

		cM1 = (cod % y4) / m1;
		cM2 = (cod % m1) / m2;

		cD1 = (cod % m2) / d1;
		cD2 = (cod % d1) / d2;

		// coding biorhythm formula		
		int codbio = (pow(Y1 - cY1, 2) + pow(Y2 - cY2, 2) + pow(Y3 - cY3, 2) + pow(Y4 - cY4, 2)) * (pow(M1 - cM1, 2) + pow(M2 - cM2, 2)) * (pow(D1 - cD1, 2) + pow(D2 - cD2, 2));

		if (minbio <= codbio) {
			if (minbio == codbio && minday > cod) {
				minbio = codbio;
				minday = cod;
			}
			else if (minbio < codbio) {
				minbio = codbio;
				minday = cod;
			}
		}
	}

	printf("%d", minday);

	return 0;
}