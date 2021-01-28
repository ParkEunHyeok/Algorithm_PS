#include <stdio.h>

int main() {
    int n;
    int dp[100002];
    scanf("%d", &n);

    dp[1]=3, dp[2]=7;
    for(int i=3; i<=n; i++) {
        dp[i] = ((dp[i-1]*2) + dp[i-2]) % 9901;
    }

    printf("%d", dp[n]);
    return 0;
}