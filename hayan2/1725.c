#define _CRT_SECURE_NO_WARNINGS
#define ull unsigned long long
#define MAX(a, b) a > b ? a : b
#define MIN(a, b) a > b ? b : a
#include <stdio.h>
#include <stdlib.h>

typedef struct Square {
	ull width;
	ull height;
}Square;

ull maxArea = 0;

Square* generateSquare() {
	return (Square*)malloc(sizeof(Square));
}

void initSquare(Square* square) {
	square->width = square->height = 0;
}

int main(void) {
	Square* square = generateSquare();
	initSquare(square);
	ull h;
	int N;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%lld", &h);

		if (square->width == 0 && square->height == 0) {
			square->width = 1;
			square->height = h;
		}
		// add -> width++; height = MIN(height, h); OR just one histogram
		else if (square->width * square->height <= (square->width + 1) * MIN(square->height, h)) {
			if (square->width * square->height < h && MIN(square->height, h) * (square->width + 1) < h) {
				square->width = 1;
				square->height = h;
			}
			else {
				square->width++;
				square->height = (square->height != 0) ? MIN(square->height, h) : h;
			}
		}
		else {
			initSquare(square);
		}

		maxArea = MAX(maxArea, square->width * square->height);
	}

	free(square);

	printf("%d", maxArea);

	return 0;
}