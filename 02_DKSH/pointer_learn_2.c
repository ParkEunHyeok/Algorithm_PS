#include <stdio.h>

int main() {
    int a[] = {1,2,3,4};
    printf("a = %u\n", *a);
    printf("*(a+1) = %u\n", *(a+1));
    printf("*(a+2) = %u\n", *(a+2));
    return 0;
}