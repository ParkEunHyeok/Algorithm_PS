#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int level[101];
    for(int i=0; i<n; i++) {
        scanf("%d", &level[i]);
    }
    if(n==1) {
        printf("0");
        return 0;
    }
    int count = 0;
    for(int i=n-1; i>=1; i--) {
        while(level[i] <= level[i-1]) {
            level[i-1]--;
            count++;
        }
    }
    printf("%d", count);
    return 0;
}