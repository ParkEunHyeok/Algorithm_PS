#include <stdio.h>

int main() {
    int num;
    scanf("%d", &num);
    num = 1000 - num;
    int money[6] = {500,100,50,10,5,1};
    int count = 0;
    for(int i=0; i<6; i++) {
        count += num/money[i];
        num -= money[i]*(num/money[i]);
    }
    printf("%d", count);
    return 0;
}