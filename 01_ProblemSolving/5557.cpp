#include <iostream>
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    int arr[102] = {0,};
    ll dp[102][21] = {0,};

    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> arr[i];
    }

    dp[1][arr[1]]++;
    
    for(int i=2; i<n; i++) {
        for(int j=0; j<=20; j++) {
            if(dp[i-1][j]) {
                if(j+arr[i]<=20) {
                    dp[i][j+arr[i]] += dp[i-1][j];
                }
                if(0<=j-arr[i]) {
                    dp[i][j-arr[i]] += dp[i-1][j];
                }
            }
        }
    }

    cout << dp[n-1][arr[n]];
    return 0;
}