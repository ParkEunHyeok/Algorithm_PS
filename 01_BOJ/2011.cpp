#include <iostream>
using namespace std;

int main() {
    int dp[5001]={0,};
    int arr[5001]={0,};
    string str;
    cin >> str;

    for(int i=1; i<=str.length(); i++) {
        arr[i] = str[i-1]-'0';
    }

    if(str[0]=='0') {
        cout << 0;
        return 0;
    }
    dp[0]=1;
    
    for(int i=1; i<=str.length(); i++) {
        if(1<=arr[i]&&arr[i]<=9) dp[i] = (dp[i] + dp[i-1])%1000000;
        if(i==1) continue;
        int num = arr[i-1]*10 + arr[i];
        if(10<=num && num<=26) dp[i] = (dp[i]+dp[i-2])%1000000;
    }

    cout << dp[str.length()];
    return 0;
}