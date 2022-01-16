#include <iostream>
using namespace std;

string str;
int result=0;
bool visited[52];

int func(int idx) {
    int cnt = 0;

    for(int i=idx; i<str.length(); i++) {
        if(str[i]=='(' && !visited[i]) {
            visited[i] = true;
            cnt--;
            cnt += (str[i-1]-'0')*(func(idx+1));
        }
        else if(str[i]==')' && !visited[i]) {
            visited[i] = true;
            return cnt;
        }
        else if(!visited[i]) {
            visited[i] = true;
            cnt++;
        }
    }

    return cnt;
}

int main() {
    cin >> str;
    cout << func(0);
    return 0;
}