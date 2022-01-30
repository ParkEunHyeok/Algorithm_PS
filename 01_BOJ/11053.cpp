#include <iostream>
using namespace std;

int n;
int dp[1004], arr[1004];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> arr[i];
        dp[i] = 1;
    }

    int res = 1;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<i; j++) {
            if(arr[i] > arr[j]) {
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
        res = max(res, dp[i]);
    }

    cout << res;
    return 0;
}