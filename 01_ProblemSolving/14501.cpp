#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    // dp[i] : i번째 날 까지의 최대 수익
    int day[17], pay[17], dp[17]={0,};
    for(int i=1; i<=n; i++) cin >> day[i] >> pay[i];
    
    int result = 0;
    for(int i=1; i<=n; i++) {
        if((i+day[i]-1)<=n) {   // 상담을 할 수 있는 기간이면 수익 계산
            dp[i+day[i]] = max(dp[i+day[i]], dp[i]+pay[i]);
        }
        dp[i+1] = max(dp[i], dp[i+1]);  // 이전날이 다음날보다 수익이 높다면 같게 함
    }
    for(int i=1; i<=(n+1); i++) {
        if(result < dp[i]) result = dp[i];
    }

    cout << result;
    return 0;  
}