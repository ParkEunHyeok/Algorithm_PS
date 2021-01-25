#include <stdio.h>

int max(int a, int b) {
    if(a>b) return a;
    else return b;
}

int main() {
    int n;
    int arr[10001];
    int dp[10001];
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }

    dp[0]=arr[0];
    dp[1]=dp[0]+arr[1];
    dp[2]=max(max(dp[1],arr[1]+arr[2]),dp[0]+arr[2]);
    for(int i=3; i<n; i++) {
        dp[i] = max(dp[i-1],max(dp[i-3]+arr[i-1]+arr[i], dp[i-2]+arr[i]));
    }

    printf("%d", dp[n-1]);
    return 0;
}