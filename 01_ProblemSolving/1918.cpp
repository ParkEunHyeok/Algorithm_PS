#include <iostream>
#include <stack>
using namespace std;

int main() {
    string str;
    cin >> str;

    stack<char> s;
    
    for(int i=0; i<str.length(); i++) {
        if('A'<=str[i] && str[i]<='Z') cout << str[i];
        else {
            if(str[i]=='*' || str[i]=='/') {
                while(!s.empty() && (s.top()=='*' || s.top()=='/')) {
                    cout << s.top();
                    s.pop();
                }
                s.push(str[i]);
            }
            else if(str[i]=='+' || str[i]=='-') {
                while(!s.empty() && s.top()!='(') {
                    cout << s.top();
                    s.pop();
                }
                s.push(str[i]);
            }
            else if(str[i]=='(') {
                s.push(str[i]);
            }
            else if(str[i]==')'){
                while(!s.empty() && s.top()!='(') {
                    cout << s.top();
                    s.pop();
                }
                s.pop();
            }
        }
    }

    while(!s.empty()) {
        cout << s.top();
        s.pop();
    }

    return 0;
}