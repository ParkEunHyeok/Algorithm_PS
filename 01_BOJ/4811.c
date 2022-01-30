#include <stdio.h>
#define ll long long

int n;
ll dp[31][31];

ll dfs(int w, int h) {
    if(dp[w][h]) return dp[w][h];

    if(w==0) return 1;

    // 메모이제이션
    dp[w][h] = dfs(w-1, h+1);
    if(h>0) dp[w][h] += dfs(w, h-1);

    return dp[w][h];
}

int main() {
    while(1) {
        scanf("%d", &n);
        if(n==0) break;

        printf("%lld\n", dfs(n, 0));
    }
    return 0;
}