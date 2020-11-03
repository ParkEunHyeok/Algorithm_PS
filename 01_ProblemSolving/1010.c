#include <stdio.h>

int main() {
    int dp[31][31] = {0,};

    dp[0][0] = 1;

    for(int i=1; i<31; i++) {
        dp[i][0] = 1;
        dp[i][1] = i;
        for(int j=1; j<i; j++) {
            dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
        }
        dp[i][i] = 1;
    }

    int cycle;
    scanf("%d", &cycle);

    for(int i=0; i<cycle; i++) {
        int n,m;
        scanf("%d %d", &n, &m);

        printf("%d\n", dp[m][n]);
    }

    return 0;
}
//