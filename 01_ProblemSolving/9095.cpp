// 점화식 d[i] = d[i-1] + d[i-2] + d[i-3]
#include <stdio.h>

int main() {
    int n, dp[11] = {};
    dp[1]=1; dp[2]=2; dp[3]=4;
    scanf("%d\n",&n);
    for(int i=4; i<=10; i++) {
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    }
    for(int i=0; i<n; i++) {
        int number;
        scanf("%d\n",&number);
        printf("%d\n", dp[number]);
    }
    return 0;
}