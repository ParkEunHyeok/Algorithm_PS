#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> time, pay, dp;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    time.resize(n+2);
    pay.resize(n+2);
    dp.resize(n+2);
    for(int i=1; i<=n; i++) {
        cin >> time[i] >> pay[i];
    }

    int res = 0;
    for(int i=1; i<=n+1; i++) {
        res = max(res, dp[i]);
        int next = i+time[i];
        if(next>n+1) continue;

        dp[next] = max(dp[next], res+pay[i]);
    }

    cout << res;
    return 0;
}