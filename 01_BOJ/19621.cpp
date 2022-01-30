#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    vector<int> v, dp;
    cin >> n;

    for(int i=0; i<n; i++) {
        int s, e, cost;
        cin >> s >> e >> cost;
        v.push_back(cost);
    }

    dp.resize(n);    
    dp[0] = v[0];
    dp[1] = max(dp[0], v[1]);

    for(int i=2; i<n; i++) {
        dp[i] = max(dp[i-1], v[i] + dp[i-2]);
    }

    cout << dp[n-1];
    return 0;
}