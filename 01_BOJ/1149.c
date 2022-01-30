#include <stdio.h>

int min(int a, int b) {
    if(a<b) return a;
    else return b;
}

int main() {
    int n;  // 집의 개수
    int arr[3][1002];
    int dp[3][1002];
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        for(int j=0; j<3; j++) {
            scanf("%d", &arr[j][i]);
        }
    }

    dp[0][0]=arr[0][0], dp[1][0]=arr[1][0], dp[2][0]=arr[2][0];
    for(int i=1; i<n; i++) {
        dp[0][i] = arr[0][i] + min(dp[1][i-1], dp[2][i-1]);
        dp[1][i] = arr[1][i] + min(dp[0][i-1], dp[2][i-1]);
        dp[2][i] = arr[2][i] + min(dp[0][i-1], dp[1][i-1]);
    }

    int temp = min(dp[0][n-1], dp[1][n-1]);
    int result = min(temp, dp[2][n-1]);
    printf("%d", result);
    return 0;
}