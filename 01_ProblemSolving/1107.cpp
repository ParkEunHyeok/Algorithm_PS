#include <iostream>
using namespace std;

bool btn[12];

bool check(int channel) {
    string str = to_string(channel);

    for(int i=0; i<str.length(); i++) {
        if(btn[str[i]-'0']) return false;
    }

    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m, tmp;
    string str;
    
    cin >> n >> m;
    for(int i=0; i<m; i++) {
        cin >> tmp;
        btn[tmp] = true;
    }

    str = to_string(n);
    int res = abs(n-100);

    for(int i=0; i<=999999; i++) {
        if(check(i)) {
            int diff = abs(n-i) + to_string(i).length();
            res = min(res, diff);
        }
    }

    cout << res;
    return 0;
}