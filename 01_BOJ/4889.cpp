#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n = 1;
    while(1) {
        string str;
        cin >> str;

        if(str[0]=='-') break;

        stack<char> s;
        int ans = 0;
        for(int i=0; i<str.length(); i++) {
            if(str[i]=='}' && !s.empty() && s.top()=='{') {
                s.pop();
            }
            else s.push(str[i]);
        }
        
        // 남은게 홀수면 고칠 수 없으므로 0
        // 두개를 뽑아서 같으면 +1, 다르면 +2

        if(s.size()%2==1) ans = 0;
        else {
            while(!s.empty()) {
                char first = s.top();
                s.pop();
                char second = s.top();
                s.pop();

                if(first==second) ans++;
                else ans += 2;
            }
        }

        cout << n << ". " << ans << "\n";
        n++;
    }

    return 0;
}