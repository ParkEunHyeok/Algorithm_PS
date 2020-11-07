#include <algorithm>
#include <iostream>
#include <stack>
using namespace std;
int n;
int main(void)
{
    cin >> n;
    for(int i=1; i<=n; i++) {
    stack<int> s;
    string str;
    cin >> str;
    int flag = 0;
    for(int i=0; i<str.size(); i++) {
        if(str[i]=='(')
        {
            s.push(1);
        }
        else if(str[i]==')')
        {
            if(s.empty())
            {
                flag = 1;
            } else {
                s.pop();
            }
        }
    }
    if(!s.empty() || flag == 1){
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }
    }
}