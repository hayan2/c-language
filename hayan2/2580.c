#define _CRT_SECURE_NO_WARNINGS
#define ARRAY_LEN 9
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int sudoku[ARRAY_LEN * ARRAY_LEN + 1];

int check(int x) {
	// ARRAY_LEN * row + col = x
	int row = x / ARRAY_LEN;
	int col = x % ARRAY_LEN;

	// 3x3
	for (int i = row / (ARRAY_LEN / 3) * (ARRAY_LEN / 3); i < row / (ARRAY_LEN / 3) * (ARRAY_LEN / 3) + (ARRAY_LEN / 3); i++) {
		for (int j = col / (ARRAY_LEN / 3) * (ARRAY_LEN / 3); j < col / (ARRAY_LEN / 3) * (ARRAY_LEN / 3) + (ARRAY_LEN / 3); j++) {
			if (row != i || col != j) {
				if (sudoku[x] == sudoku[ARRAY_LEN * i + j]) {
					return 0;
				}
			}
		}
	}

	for (int i = 0; i < ARRAY_LEN; i++) {
		if (x != ((row * ARRAY_LEN) + i) && sudoku[x] == sudoku[(row * ARRAY_LEN) + i]) {
			return 0;
		}
		if (x != (col + (ARRAY_LEN * i)) && sudoku[x] == sudoku[col + (ARRAY_LEN * i)]) {
			return 0;
		}
	}

	return 1;
}

void DFS(int x) {
	if (x == ARRAY_LEN * ARRAY_LEN) {
		for (int i = 0; i < ARRAY_LEN * ARRAY_LEN; i++) {
			if (i % (ARRAY_LEN) == 0 && i != 0) {
				printf("\n");
			}
			printf("%d ", sudoku[i]);
		}
		exit(0);
	}

	if (sudoku[x] != 0) {
		DFS(x + 1);
	}
	else {
		for (int i = 1; i <= ARRAY_LEN; i++) {
			sudoku[x] = i;
			if (check(x)) {
				DFS(x + 1);
			}
			sudoku[x] = 0;
		}
	}
}

int main(void) {
	for (int i = 0; i < ARRAY_LEN * ARRAY_LEN; i++) {
		scanf("%d", &sudoku[i]);
	}

	DFS(0);

	return 0;
}