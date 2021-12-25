#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> t;

    while(t--) {
        int n;
        cin >> n;
        vector<int> arr(n), dp(n);
        int res = 0;

        for(int i=0; i<n; i++) {
            cin >> arr[i];
            
            if(i==0) {
                dp[0] = arr[i];
                res = dp[0];
                continue;
            }

            dp[i] = max(0, dp[i-1]) + arr[i];
            res = max(res, dp[i]);
        }

        cout << res << "\n";
    }

    return 0;
}