#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int n;
    int arr[1001]={0,};
    vector<int> dp[1001];
    cin >> n;

    int mx = 0, mx_idx = 0;
    for(int i=0; i<n; i++) {
        cin >> arr[i];
        dp[i].push_back(arr[i]);
        
        for(int j=0; j<i; j++) {
            if(arr[j] < arr[i] && dp[j].size() >= dp[i].size()) {
                dp[i].resize(dp[j].size()+1);
                for(int k=0; k<dp[j].size(); k++) {
                    dp[i][k+1] = dp[j][k];
                }
            }
        }

        if(dp[i].size() > mx) {
            mx = dp[i].size();
            mx_idx = i;
        }
    }

    cout << mx << "\n";
    for(int i=dp[mx_idx].size()-1; i>=0; i--) {
        cout << dp[mx_idx][i] << " ";
    }
    return 0;
}