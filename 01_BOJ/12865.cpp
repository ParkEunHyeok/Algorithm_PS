#include <iostream>
using namespace std;

int w[102], v[102];
int dp[102][100001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, k;
    cin >> n >> k;

    for(int i=1; i<=n; i++) {
        cin >> w[i] >> v[i];
    }

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=k; j++) {
            if(w[i] <= j) {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i]]+v[i]);
            } else dp[i][j] = dp[i-1][j];
        }
    }

    cout << dp[n][k];
    return 0;   
}