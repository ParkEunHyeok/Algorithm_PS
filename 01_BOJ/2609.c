#include <stdio.h>

int main() {
    int a,b;
    scanf("%d%d",&a,&b);
    int result;
    int i=1;
    while(1) {
        if(a%i==0 && b%i==0) result=i;
        if(i%a==0 && i%b==0) {
            printf("%d\n%d",result, i);
            break;
        }
        i++;
    }
    return 0;
}