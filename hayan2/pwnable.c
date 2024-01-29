#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char secret[16] = "secret message";
    char barrier[4];
    char name[8];

    memset(barrier, 0, 4);

    printf("Your name : ");
    read(0, name, 12);
    printf("Your name is %s", name);
    
    return 0;
}