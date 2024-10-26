#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void quick_sort(int* arr, int L, int R);

int main(void) {
	int arr[1001];
	int n, k;

	scanf("%d %d", &n, &k);

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	quick_sort(arr, 0, n - 1);

	printf("%d", arr[k - 1]);

	return 0;
}

void quick_sort(int arr[], int L, int R) {
	int pivot = arr[(L + R) / 2], left = L, right = R;

	while (left <= right) {
		while (arr[left] > pivot) {
			left++;
		}
		while (arr[right] < pivot) {
			right--;
		}

		if (left <= right) {
			if (left != right) {
				int temp = arr[left];
				arr[left] = arr[right];
				arr[right] = temp;				
			}
			left++;
			right--;
		}
	}

	if (L < right) {
		quick_sort(arr, L, right);
	}
	if (left < R) {
		quick_sort(arr, left, R);
	}	
}