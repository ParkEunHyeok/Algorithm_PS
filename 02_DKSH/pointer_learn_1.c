#include <stdio.h>

int main() {
    int a= 5;
    int *pt;
    pt = &a;
    printf("%u\n", *pt);
    printf("%u", pt);

    return 0;
}