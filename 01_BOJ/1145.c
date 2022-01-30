#include <stdio.h>

int main() {
    int num[5];
    for(int i=0; i<5; i++) {
        scanf("%d", &num[i]);
    }

    for(int i=1; i<=1000000; i++) {
        int count = 0;
        for(int j=0; j<5; j++) {
            if(i%num[j]==0) count++;
        }
        if(count >= 3) {
            printf("%d", i);
            return 0;
        }
    }
}