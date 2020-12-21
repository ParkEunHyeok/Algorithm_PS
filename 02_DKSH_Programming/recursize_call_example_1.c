#include <stdio.h>

int factorial_r(int n) {
    if(n>1) {
        return (n*factorial_r(n-1));
    }
    else
    {
        return 1;
    }
}

int factorial_l(int n) {
    int i, p=1;
    for(i=1; i<=n; i++) {
        p*=i;
    }
    return p;
}

int main() {
    int recursive, loop;
    recursive = factorial_r(5);
    loop = factorial_l(5);
    printf("재귀호출 %d\n", recursive);
    printf("반복문 %d\n", loop);
    return 0;
}