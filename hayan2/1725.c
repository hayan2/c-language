#define _CRT_SECURE_NO_WARNINGS
#define MAX(a, b) a > b ? a : b
#define MIN(a, b) a > b ? b : a
#define ARRAY_LEN 100001
#include <stdio.h>
#include <stdlib.h>

typedef struct Square {
	int width;
	int height;
}Square;

int maxArea = 0;

Square* generateSquare() {
	return (Square*)malloc(sizeof(Square));
}

void initSquare(Square* square) {
	square->width = square->height = 0;
}

int main(void) {
	Square* square = generateSquare();
	int N, h;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &h);

		// add -> width++; height = MIN(height, h);
				 		
		// keep (initialize)

		// just one histogram
	}

	return 0;
}