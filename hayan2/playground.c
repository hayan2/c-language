#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h> 
#include <stdio.h> 
#include <string.h> 
#define M 10000 

int main()
{
    char names[M][15];
    int n, i;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%s", names[i]);

    qsort(names, n, 15, (int (*)(const void *, const void *))strcmp);

    for(i = 0; i < n; i++)
        printf("%s\n", names[i]);
} 