#include <stdio.h>
int main() {
    int t;
    scanf("%d", &t);
    for(int i=1;i<=t; i++) {
        for(int j=1;j<=t-i; j++) {
            printf(" ");
        }
        for(int k=0; k<i; k++) {
            printf("*");
        }
        printf("\n");
    }
}