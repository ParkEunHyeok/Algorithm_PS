#include <stdio.h>

int smaller(int a, int b) {
    if(a<=b) return a;
    else return b;
}

int main() {
    int n, m; // 세로N, 가로M
    scanf("%d %d", &n, &m);

    if(n==1) printf("1");
    else if(n==2) printf("%d", smaller(4, (m+1)/2));
    else {
        if(m<=6) {
            printf("%d", smaller(4, m));
        } else printf("%d", m-2);
    }

    return 0;
}