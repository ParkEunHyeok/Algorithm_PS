#include <stdio.h>

int fibo(int num) {
    if(num==0) return 0;
    else if(num==1) return 1;
    else return fibo(num-1) + fibo(num-2);
}

int main() {
    int num;
    printf("\n개월 수 입력: " );
    scanf("%d", &num);
    printf("총 토끼 쌍 : %d", fibo(num+1));
    return 0;
}