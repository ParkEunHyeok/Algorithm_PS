#include <stdio.h>

int bigger(int a, int b) {
    if(a>=b) return a;
    else return b;
}

int main() {
    int n;
    scanf("%d", &n);
    int dp[501][501];
    for(int i=0; i<n; i++) {
        for(int j=0; j<=i; j++) {
            scanf("%d", &dp[i][j]);
        }
    }

    int max = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<=i; j++) {
            if(j==0) dp[i][j] += dp[i-1][0];
            else if(j==i) dp[i][j] += dp[i-1][j-1];
            else dp[i][j] = bigger(dp[i][j]+dp[i-1][j-1], dp[i][j]+dp[i-1][j]);

            if(max < dp[i][j]) max = dp[i][j];
        }
    }

    printf("%d", max);
    return 0;
}