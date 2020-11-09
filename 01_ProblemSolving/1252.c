#include <stdio.h>

int main() {
    char arr[2][81];
    int result;
    scanf("%s %s", arr[0], arr[1]);
    for(int i=0; i<2; i++) {
        int number = 0;
        for(int j=0; arr[i][j]!=NULL; j++) {
            number *= 2;
            if(arr[i][j]=='0') continue;
            else {
                number += 1;
            }
        }
        result = number;
    }

    printf("%d", result);
    return 0;
}