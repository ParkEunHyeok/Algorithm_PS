#include <stdio.h>

int main() {
    int money, result=0;
    scanf("%d", &money);
    if(money==1 || money==3) {
        result = -1;
    }
    else if((money%5)%2==0) {
        result = (money/5) + ((money%5)/2);
    }
    else {
        result = ((money/5)-1) + ((money%5 +5)/2);
    }

    printf("%d", result);
    return 0;
}