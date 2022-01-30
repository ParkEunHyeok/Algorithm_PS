#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    while(n--) {
        string str1, str2;
        cin >> str1 >> str2;

        int cnt = 0;
        int zero_one = 0;
        int one_zero = 0;

        for(int i=0; i<str1.length(); i++) {
            if(str1[i]!=str2[i])
            {
                cnt++;
                if(str1[i]=='1') one_zero++;
                else zero_one++;
            }
        }

        cout << cnt-min(one_zero, zero_one) << "\n";
    }

    return 0;
}