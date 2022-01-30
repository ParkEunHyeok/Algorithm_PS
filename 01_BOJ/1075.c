#include <stdio.h>

int main() {
    int n, f;
    scanf("%d\n%d", &n, &f);
    n = (n/100) * 100;
    while(1) {
        if((n%f)==0) {
            //n이 f로 나누어짐.
            int result = n%100;
            if((result/10)==0)
            {
                printf("0");
            }
            printf("%d", result);
            break;
        }
        n++;
    }
    return 0;
}