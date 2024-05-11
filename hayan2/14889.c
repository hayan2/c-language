#define _CRT_SECURE_NO_WARNINGS
#define ARRAY_LEN 20
#define SCORE_DIFF 999999999
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int score[ARRAY_LEN * ARRAY_LEN + 1];
int visited[ARRAY_LEN + 1];
int N, minScoreDiff = SCORE_DIFF;

int getTeamScoreDiff() {
	int startTeamScore = 0, linkTeamScore = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visited[i] == 0 && visited[j] == 0) {
				startTeamScore += score[N * i + j];
			}
			if (visited[i] != 0 && visited[j] != 0) {
				linkTeamScore += score[N * i + j];
			}
		}
	}	

	return abs(startTeamScore - linkTeamScore);
}

void DFS(int cur, int cnt) {
	if (cnt == N / 2) {
		int teamScoreDiff = getTeamScoreDiff();		
		minScoreDiff = (minScoreDiff < teamScoreDiff) ? minScoreDiff : teamScoreDiff;		
		return;
	}

	for (int i = cur; i < N; i++) {
		if (visited[i] == 0) {
			visited[i] = 1;
			DFS(i + 1, cnt + 1);
			visited[i] = 0;
		}
	}
}

int main(void) {
	scanf("%d", &N);

	for (int i = 0; i < N * N; i++) {
		scanf("%d", &score[i]);
	}

	DFS(0, 0);

	printf("%d", minScoreDiff);

	return 0;
}