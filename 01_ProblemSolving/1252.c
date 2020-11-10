#include <stdio.h>

int main() {
    char arr[2][81];
    int sum = 0;
    scanf("%s %s", arr[0], arr[1]);

    // 이진수를 십진수로 바꾸고 더함.
    for(int i=0; i<2; i++) {
        int number = 0;
        for(int j=0; arr[i][j]!=NULL; j++) {
            number *= 2;
            if(arr[i][j]=='0') continue;
            else {
                number += 1;
            }
        }
        sum += number;
    }

    // 총합을 이진수로 바꿈.
    if((sum%2)==0) printf("1");
    sum = sum / 2;
    while(1) {
        if(sum<1) break;
        if((sum%2)==0) printf("0");
        else printf("1");
        sum = sum/2;
    }

    return 0;
}