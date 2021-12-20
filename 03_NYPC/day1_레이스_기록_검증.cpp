#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m;
    bool flag = false;
    cin >> n >> m;

    vector<int> condition(n+1, -1);

    while(m--) {
        int t, u, s;
        cin >> t >> u >> s;

        if(s==0) {
            if(condition[u]!=-1) flag = true;
            condition[u] = t;
        } else {
            if(condition[u]==-1) flag = true;
            if(t - condition[u] < 60) flag = true;
            condition[u] = -1;
        }
    }

    for(int i=1; i<=n; i++) {
        if(condition[i]!=-1) {
            flag = true;
            break;
        }
    }

    if(flag) cout << "NO";
    else cout << "YES";
    return 0;
}