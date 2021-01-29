#include <stdio.h>

int max(int a, int b) {
    if(a>b) return a;
    else return b;
}

int main() {
    int n, result=1;
    int arr[1002];
    int dp[1002];
    scanf("%d", &n);

    for(int i=1; i<=n; i++) {
        scanf("%d", &arr[i]);
    }

    for(int i=1; i<=n; i++) {
        dp[i] = 1;
    }

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=i; j++) {
            if(arr[i] > arr[j]) {
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
        result = max(result, dp[i]);
    }

    printf("%d", n-result);
    return 0;
}