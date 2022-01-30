#include <stdio.h>

int bigger(int a, int b) {
    if(a>=b) return a;
    else return b;
}

int main() {
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        int m;
        scanf("%d", &m);
        int arr[2][100001];
        int dp[2][100001];
        for(int j=0; j<2; j++) {
            for(int k=0; k<m; k++) {
                scanf("%d", &arr[j][k]);
            }
        }
        dp[0][0] = arr[0][0];
        dp[1][0] = arr[1][0];
        dp[0][1] = arr[1][0] + arr[0][1];
        dp[1][1] = arr[0][0] + arr[1][1];
        for(int j=2; j<m; j++) {
            dp[0][j] = arr[0][j] + bigger(dp[1][j-1], dp[1][j-2]);
            dp[1][j] = arr[1][j] + bigger(dp[0][j-1], dp[0][j-2]);
        }
        printf("%d\n", bigger(dp[0][m-1], dp[1][m-1]));
    }

    return 0;
}