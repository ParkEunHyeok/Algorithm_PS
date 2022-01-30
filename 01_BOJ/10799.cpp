#include <iostream>
#include <stack>
using namespace std;

int main() {
    string str;
    stack<int> s;
    int result=0, w=0;

    cin >> str;

    for(int i=0; i<str.length(); i++) {
        if(str[i]=='(') {
            w++;
        }
        else {
            w--;
            if(str[i-1]=='(') result += w;
            else result++;
        }
    }

    cout << result;
    return 0;
}