/*
dp[a][b] a는 길이, b는 마지막 숫자
dp[1][b] b는 무조건 1
dp[2][0] = 10

3자리를 만들 때 끝자리가 5가되는 경우는
dp[3][5] = 45 54 56 65 = dp[2][4] + dp[2][6]

점화식 dp[a][b] = dp[a-1][b-1] + dp[a-1][b+1]
*/
#include <stdio.h>

int main() {
    long dp[101][10] = {0,};
    int n, M = 1000000000;
    scanf("%d", &n);

    for(int i=1; i<=9; i++)
    {
        dp[1][i] = 1;
    }
    dp[1][0] = 0;
    for(int i=2; i<=n; i++)
    {
        for(int j=0; j<=9; j++)
        {
            if(j==0) dp[i][j] = dp[i-1][j+1] % M;
            else if(j==9) dp[i][j] = dp[i-1][j-1] % M;
            else dp[i][j] = (dp[i-1][j+1] +dp[i-1][j-1]) % M;
        }
    }

    long ans=0;
    for(int i=0; i<10; i++)
    {
        ans = ans + dp[n][i];
    }

    printf("%d",ans % M);
    return 0;
}