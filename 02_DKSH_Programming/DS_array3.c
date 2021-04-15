#include <stdio.h>

int main() {
    int gugu[10][10] = {0,};

    for(int i=0; i<8; i++) {
        int hsum = 0;
        for(int j=0; j<9; j++) {
            int num = (i+2) * (j+1);
            gugu[i][j] = num;
            hsum += num;
        }
        gugu[i][9] = hsum;
    }

    //result
    for(int i=0; i<8; i++) {
        for(int j=0; j<10; j++) {
            printf("%5d ", gugu[i][j]);
        }
        printf("\n");
    }

    return 0;
}