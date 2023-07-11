#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b);
int compare_desc(const void* a, const void* b);

int main(void) {
    int n, result = 0;
    int arrA[51], arrB[51];

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &arrA[i]);
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &arrB[i]);
    }

    qsort(arrA, n, sizeof(int), compare);
    qsort(arrB, n, sizeof(int), compare_desc);

    int cnt = n;

    for (int i = 0; i < n; i++) {
        result += (arrA[i] * arrB[i]);
    }

    printf("%d", result);

	return 0;
}

int compare(const void* a, const void* b) {
    int num1 = *(int*)a;
    int num2 = *(int*)b;

    if (num1 < num2) {
        return -1;
    }

    if (num1 > num2) {
        return 1;
    }

    return 0;
}

int compare_desc(const void* a, const void* b) {
    int num1 = *(int*)a;
    int num2 = *(int*)b;

    if (num1 < num2) {
        return 1;
    }

    if (num1 > num2) {
        return -1;
    }

    return 0;
}
