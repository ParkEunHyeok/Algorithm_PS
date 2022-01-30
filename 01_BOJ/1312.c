#include <stdio.h>

int main() {
    int a, b, n;
    scanf("%d %d %d", &a, &b, &n);

    a = a%b;
    for(int i=1; i<=n; i++) {
        a *= 10;
        if(i==n) {
            printf("%d", a/b);
            break;
        }else a = a%b;
    }
    
    return 0;
}