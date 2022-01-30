#include <stdio.h>

int greater(int a, int b) {
    if(a>b) return a;
    else return b;
}

int main() {
    int n, max=0;
    int arr[1001]={0,};
    int dp[1001]={0,};
    scanf("%d", &n);

    for(int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
        dp[i] = 1;

        for(int j=0; j<i; j++) {
            if(arr[j] > arr[i]) {
                dp[i] = greater(dp[i], dp[j] + 1);
            }
        }

        max = greater(max, dp[i]);
    }

    printf("%d", max);
    return 0;
}