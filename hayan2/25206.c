#define _CRT_SECURE_NO_WARNINGS
#define IDX 9
#include <stdio.h>
#include <string.h>

float score[IDX] = { 4.5, 4.0, 3.5, 3.0, 2.5, 2.0, 1.5, 1.0, 0.0 };
char grade[IDX][3] = {
	{ "A+" },
	{ "A0" },
	{ "B+" },
	{ "B0" },
	{ "C+" },
	{ "C0" },
	{ "D+" },
	{ "D0" },
	{ "F" }
};

float get_score(char* inputGrade);

int main(void) {	
	char subject[51];		
	float totalScore = 0, result = 0;
	
	for (int i = 0; i < 20; i++) {
		float inputScore;
		char inputGrade[3];
		scanf("%s %f %s", subject, &inputScore, inputGrade);

		if (inputGrade[0] == 'P') {
			continue;
		}

		float gradeScore = get_score(inputGrade);

		totalScore += inputScore;

		result += (inputScore * gradeScore);
	}

	if (result == 0.0 && totalScore == 0.0) {
		printf("0.00000");
	}
	else {
		printf("%f", result / totalScore);
	}


	return 0;
}

float get_score(char* inputGrade) {
	if (inputGrade[0] == 'F') {
		return 0.0;
	}

	for (int i = 0; i < IDX; i++) {
		if (inputGrade[0] == grade[i][0] && inputGrade[1] == grade[i][1]) {
			return score[i];
		}
	}
}