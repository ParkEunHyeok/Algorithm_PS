#include <stdio.h>

int main() {
    int n, max=0;
    int arr[1001] = {0,};
    int dp[1001] = {0,};
    scanf("%d", &n);

    for(int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
        dp[i] = arr[i];

        for(int j=0; j<i; j++) {
            if(arr[i] > arr[j] && dp[i]<dp[j]+arr[i]) {
                dp[i] = dp[j] + arr[i];
            }
        }

        if(max < dp[i]) max = dp[i];
    }

    printf("%d", max);
    return 0;
}