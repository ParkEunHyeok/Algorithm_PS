#include <stdio.h>

int main() {
    int n, k;
    int coin_count = 0;
    int arr[12]={0,};
    scanf("%d%d", &n, &k);

    for(int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }

    for(int i=n-1; i>=0; i--) {
        if(k==0) break;

        int coin = k / arr[i];
        coin_count += coin;
        k -= coin * arr[i];
    }

    printf("%d", coin_count);
    return 0;
}