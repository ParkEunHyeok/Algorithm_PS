#include <iostream>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, temp;
    stack<int> s;

    cin >> n;
    while(n--) {
        cin >> temp;
        while(!s.empty() && temp>=s.top())
            s.pop();
        s.push(temp);
    }

    cout << s.size();
    return 0;
}