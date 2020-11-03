#include <stdio.h>

int main() {
    int a,b,c,d,e;
    scanf("%d %d %d %d %d\n",&a,&b,&c,&d,&e);
    int aa= a * a;
    int bb = b * b;
    int cc = c * c;
    int dd = d * d;
    int ee = e * e;
    int result = (aa+bb+cc+dd+ee) % 10;
    printf("%d",result);
    return 0;
}