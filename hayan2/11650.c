#define _CRT_SECURE_NO_WARNINGS
#define X 0
#define Y 1
#define MAX_SIZE 100001
#define TWO_DIMENSIONAL_ARRAY 2
#include <stdio.h>

void quick_sort(int arr[][TWO_DIMENSIONAL_ARRAY], int S, int E);

int main(void) {
	int arr[MAX_SIZE][2];
	int n;

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {		
		scanf("%d %d", &arr[i][X], &arr[i][Y]);
	}

	quick_sort(arr, 0, n - 1);
	
	for (int i = 0; i < n; i++) {
		printf("%d %d\n", arr[i][X], arr[i][Y]);
	}

	return 0;
}

void quick_sort(int arr[][TWO_DIMENSIONAL_ARRAY], int S, int E) {
	int pivotX, pivotY, start, end;
	pivotX = arr[(S + E) / 2][X];
	pivotY = arr[(S + E) / 2][Y];
	start = S;
	end = E;

	while (start <= end) {
		while (arr[start][X] <= pivotX) {
			if (arr[start][X] == pivotX && arr[start][Y] < pivotY || arr[start][X] < pivotX) {
				start++;
			}			
			else {
				break;
			}
		}
		while (pivotX <= arr[end][X]) {
			if (arr[end][X] == pivotX && pivotY < arr[end][Y] || pivotX < arr[end][X]) {
				end--;
			}
			else {
				break;
			}
		}

		if (start <= end) {
			if (arr[start][X] != arr[end][X]) {
				int tempX = arr[start][X];
				int tempY = arr[start][Y];
				arr[start][X] = arr[end][X];
				arr[start][Y] = arr[end][Y];
				arr[end][X] = tempX;
				arr[end][Y] = tempY;
			}
			else {
				if (arr[end][Y] <= arr[start][Y]) {
					int tempX = arr[start][X];
					int tempY = arr[start][Y];
					arr[start][X] = arr[end][X];
					arr[start][Y] = arr[end][Y];
					arr[end][X] = tempX;
					arr[end][Y] = tempY;
				}
			}
			start++;
			end--;
		}
	}

	if (S < end) {
		quick_sort(arr, S, end);
	}
	if (start < E) {
		quick_sort(arr, start, E);
	}
}