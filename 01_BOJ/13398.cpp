#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int n;
    int arr[100002]={0,};
    int dp[100002][2]={0,};
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> arr[i];
        dp[i][0] = dp[i][1] = arr[i];
    }
    int result = arr[0];

    for(int i=1; i<n; i++) {
        // i번째 삭제 X
        dp[i][0] = max(dp[i-1][0]+arr[i], arr[i]);
        // i번째 삭제
        dp[i][1] = max(dp[i-1][0], dp[i-1][1]+arr[i]);
        result = max(result, max(dp[i][0], dp[i][1]));
    }

    cout << result;
    return 0;
}