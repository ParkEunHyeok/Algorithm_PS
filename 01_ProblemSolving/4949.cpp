#include <iostream>
#include <stack>
using namespace std;

int main() {
    while(1) {
        bool flag = false;
        stack<int> s;
        string str;

        getline(cin, str);

        if(str[0]=='.') break;

        for(int i=0; i<str.length(); i++) {
            if(str[i]=='[') s.push(1);
            else if(str[i]=='(') s.push(2);
            else if(str[i]==']') {
                if(s.empty()) {
                    cout << "no\n";
                    flag = true;
                    break;
                } else {
                    if(s.top()==1) s.pop();
                    else {
                        cout << "no\n";
                        flag = true;
                        break;
                    }
                }
            }
            else if(str[i]==')') {
                if(s.empty()) {
                    cout << "no\n";
                    flag = true;
                    break;
                } else {
                    if(s.top()==2) s.pop();
                    else {
                        cout << "no\n";
                        flag = true;
                        break;
                    }
                }
            }
        }

        if(flag) continue;
        if(s.empty()) cout << "yes\n";
        else cout << "no\n";
    }

    return 0;
}