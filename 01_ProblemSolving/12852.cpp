#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    int dp[1000002];
    int prev[1000002];

    cin >> n;

    dp[1] = 0;
    prev[1] = -1;
    for(int i=2; i<=n; i++) {
        dp[i] = dp[i-1] + 1;
        prev[i] = i - 1;

        if(i%2==0 && dp[i] > dp[i/2] + 1) {
            dp[i] = dp[i/2] + 1;
            prev[i] = i/2;
        }
        if(i%3==0 && dp[i] > dp[i/3] + 1) {
            dp[i] = dp[i/3] + 1;
            prev[i] = i/3;
        }
    }

    cout << dp[n] << "\n";
    while(n != -1) {
        cout << n << " ";
        n = prev[n];
    }

    return 0;
}