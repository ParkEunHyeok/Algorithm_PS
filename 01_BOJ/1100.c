#include <stdio.h>

int main() {
    char chess[20][20];
    int count = 0;

    for(int i=0; i<8; i++) {
        scanf("%s", chess[i]);
    }

    for(int i=0; i<8; i++) {
        for(int j=0; j<8; j++) {
            if(chess[i][j]=='.') continue;

            if((i%2)==1) {  // 홀수 번째 줄이라면
                if((j%2)==1) { // 홀수 번째 칸
                    count++;
                }
            }
            if((i%2)==0) {  // 짝수 번째 줄이라면
                if((j%2)==0) { // 짝수 번째 칸
                    count++;
                }
            }
        }
    }

    printf("%d", count);
    return 0;
}