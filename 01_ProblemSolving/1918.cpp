#include <iostream>
#include <stack>
using namespace std;

int main() {
    string str;
    cin >> str;

    int status = 0; // 상태 1:다음 수식 push, 2:다음 수식 pop
    stack<char> s;
    for(int i=0; i<str.length(); i++) {
        if(str[i]=='(') {
            status++;
        }
        else if(str[i]==')') {
            cout << s.top();
            status--;
            s.pop();
        }
        else if(str[i]=='+' || str[i]=='-' || str[i]=='*' || str[i]=='/') {
            s.push(str[i]);
        }
        else {  // 피연산자
            cout << str[i];
        }
    }
    while(!s.empty()) {
        cout << s.top();
        s.pop();
    }

    return 0;
}