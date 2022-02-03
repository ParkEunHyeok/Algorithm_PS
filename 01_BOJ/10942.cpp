#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m, s, e;
    int arr[2002] = {0,};
    bool dp[2002][2002] = {0,};

    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    for(int i=0; i<n; i++) dp[i][i] = true;
    for(int i=0; i<n-1; i++) {
        if(arr[i]==arr[i+1]) {
            dp[i][i+1] = true;
        }
    }

    for(int i=n-3; i>=0; i--) {
        for(int j=i+2; j<n; j++) {
            if(arr[i]==arr[j] && dp[i+1][j-1]) {
                dp[i][j] = true;
            }
        }
    }

    cin >> m;
    for(int i=0; i<m; i++) {
        cin >> s >> e;
        cout << dp[s][e] << "\n";
    }

    return 0;
}