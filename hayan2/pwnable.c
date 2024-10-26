#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    // 28 x 30 o
    char buf[0x28];

    scanf("%s", buf);

    printf("%d\n%s", strlen(buf), buf);

    return 0;
}