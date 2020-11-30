#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int day[17], pay[17], dp[17];
    for(int i=1; i<=n; i++) cin >> day[i] >> pay[i];

    int result = 0;
    for(int i=1; i<=n; i++) {
        if(i+day[i]<=n+1) {
            dp[i+day[i]] = max(dp[i+day[i]], dp[i]+pay[i]);
            result = max(result, dp[i+day[i]]);
        }   
        dp[i+1] = max(dp[i+1], dp[i]);
        result = max(result, dp[i+1]);
    }

    cout << result;
    return 0;  
}