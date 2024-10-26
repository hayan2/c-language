#define _CRT_SECURE_NO_WARNINGS
#define MM_NUM 1352188456
#define OPERATOR_LEN 5
#define ARRAY_LEN 12
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int N, max = -MM_NUM, min = MM_NUM;
// + - * /
int operators[OPERATOR_LEN];
int arr[ARRAY_LEN];

void DFS(int cnt, int result) {	
	if (cnt == N - 1) {
		max = (max < result) ? result : max;
		min = (min < result) ? min : result;
		return;
	}

	for (int i = 0; i < OPERATOR_LEN - 1; i++) {
		if (operators[i] > 0) {
			operators[i]--;
			switch (i) {
			case 0:
				DFS(cnt + 1, result + arr[cnt + 1]);
				break;
			case 1:
				DFS(cnt + 1, result - arr[cnt + 1]);
				break;
			case 2:
				DFS(cnt + 1, result * arr[cnt + 1]);
				break;
			case 3:
				DFS(cnt + 1, result / arr[cnt + 1]);				
				break;
			}
			operators[i]++;
		}
	}
}

int main(void) {
	scanf("%d", &N);
		
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	for (int i = 0; i < OPERATOR_LEN - 1; i++) {
		scanf("%d", &operators[i]);
	}

	DFS(0, arr[0]);
			
	printf("%d %d", max, min);

	return 0;
}