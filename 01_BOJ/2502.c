#include <stdio.h>

int main() {
    int day, dduk;   // 넘어온 날, 호랑이에게 준 떡의 개수
    scanf("%d%d", &day, &dduk);

    int dp[32];
    for(int i=1; i<=100000; i++) {
        for(int j=i; j<=100000; j++) {
            dp[1] = i, dp[2] = j;
            for(int k=3; k<=30; k++) {
                dp[k] = dp[k-1] + dp[k-2];
                
                if(k==day && dp[k]==dduk) {
                    printf("%d\n%d", dp[1], dp[2]);
                    return 0;
                }
                else if(dp[k] > dduk) break; 
            }
        }
    }

    return 0;
}