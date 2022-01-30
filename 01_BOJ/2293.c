#include <stdio.h>

int main() {
    int n, k;
    int money[101] = {0,};
    int target[10001] = {0,};
    target[0] = 1;

    scanf("%d%d", &n, &k);
    
    for(int i=0; i<n; i++) {
        scanf("%d", &money[i]);
    }

    for(int i=0; i<n; i++) {
        for(int j=1; j<=k; j++) {
            if(j>=money[i]) {
                target[j] += target[j-money[i]];
            }
        } 
    }

    printf("%d", target[k]);
    return 0;
}