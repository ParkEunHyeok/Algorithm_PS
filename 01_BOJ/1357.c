#include <stdio.h>

int reverse(int num) {
    if(num/1000!=0) {
        return (num/1000) + ((num%1000)/100)*10 + ((num%100)/10)*100 + (num%10)*1000;
    }
    else if(num/100!=0) {
        return (num/100) + ((num%100)/10)*10 + (num%10)*100;
    }
    else if(num/10!=0) {
        return (num/10) + (num%10)*10;
    }
    else {
        return num;
    }
}

int main(void) {
    int n1, n2;
    scanf("%d %d", &n1, &n2);

    int result = reverse(reverse(n1) + reverse(n2));
    printf("%d", result);
    return 0;
}