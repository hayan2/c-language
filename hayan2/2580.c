#define _CRT_SECURE_NO_WARNINGS
#define ARRAY_LEN 9
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int sudoku[ARRAY_LEN * ARRAY_LEN + 1] = {
	0, 3, 5, 4, 6, 9, 2, 7, 8,
	7, 8, 2, 1, 0, 5, 6, 0, 9,
	0, 6, 0, 2, 7, 8, 1, 3, 5,
	3, 2, 1, 0, 4, 6, 8, 9, 7,
	8, 0, 4, 9, 1, 3, 5, 0, 6,
	5, 9, 6, 8, 2, 0, 4, 1, 3,
	9, 1, 7, 6, 5, 2, 0, 8, 0,
	6, 0, 3, 7, 0, 1, 9, 5, 2,
	2, 5, 8, 3, 9, 4, 7, 6, 0 
};

int check(int x) {
	int row = x / ARRAY_LEN;
	int col = x % ARRAY_LEN;

	// 3x3
	for (int i = row / (ARRAY_LEN / 3) * (ARRAY_LEN / 3); i < row / (ARRAY_LEN / 3) * (ARRAY_LEN / 3) + (ARRAY_LEN / 3); i++) {
		for (int j = col / (ARRAY_LEN / 3) * (ARRAY_LEN / 3); j < col / (ARRAY_LEN / 3) * (ARRAY_LEN / 3) + (ARRAY_LEN / 3); j++) {
			if (row != i && col != j) {
				if (sudoku[x] == sudoku[ARRAY_LEN * i + j]) {
					return 0;
				}
			}
		}
	}

	for (int i = 0; i < ARRAY_LEN; i++) {
		if (sudoku[x] == sudoku[row * ARRAY_LEN + i] || sudoku[x] == sudoku[col + (ARRAY_LEN * i)]) {
			return 0;
		}
	}

	return 1;
}

void DFS(int x) {
	if (x == ARRAY_LEN * ARRAY_LEN) {
		return;
	}

	// ARRAY_LEN * row + col = x
	int row = x / ARRAY_LEN;
	int col = x % ARRAY_LEN;

	for (int i = 1; i <= ARRAY_LEN * ARRAY_LEN; i++) {
		if (i % ARRAY_LEN == 0) {
			sudoku[x] = ARRAY_LEN;
		}
		else {
			sudoku[x] = i % ARRAY_LEN;
		}		
		if (check(x)) {
			DFS(x + 1);
		}
	}
}

int main(void) {
	/*
	FILE* fp = fopen("test.txt", "r");

	for (int i = 0; i < ARRAY_LEN * ARRAY_LEN; i++) {
		fscanf(fp, "%d", &sudoku[i]);
	}
	*/

	DFS(0);

	for (int i = 0; i < ARRAY_LEN * ARRAY_LEN; i++) {
		if (i % (ARRAY_LEN) == 0 && i != 0) {
			printf("\n");
		}
		printf("%d ", sudoku[i]);
	}

	return 0;
}