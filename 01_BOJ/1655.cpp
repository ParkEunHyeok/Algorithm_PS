#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    priority_queue<int> M;
    priority_queue<int, vector<int>, greater<int>> m;

    cin >> n;
    while(n--) {
        int num;
        cin >> num;

        if(M.size()<=m.size()) M.push(num);
        else m.push(num);

        if(!M.empty() && !m.empty()) {
            if(M.top() > m.top()) {
                int tmp1 = M.top();
                int tmp2 = m.top();
                M.pop();
                m.pop();
                M.push(tmp2);
                m.push(tmp1);
            }
        }

        cout << M.top() << "\n";
    }

    return 0;
}