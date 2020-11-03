#include <stdio.h>
#include <stdlib.h>

int main()
{
    char A[333340] = {'\0',};
    char B[8][8] = {"000","001","010","011","100","101","110","111"};
    char C[8][8] = {"0","1","10","11","100","101","110","111"};

    scanf("%s",A);
    printf("%s",C[A[0]-'0']);

    for(int i=1; A[i]!='\0'; i++) {
        printf("%s", B[A[i] - '0']);
    }
    
    return 0;
}