#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, a, b, l, p;
    int idx = 0, result = 0;
    bool flag = false;
    vector<pair<int, int>> v;
    priority_queue<int> pq;

    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> a >> b;
        v.push_back({a,b});
    }
    sort(v.begin(), v.end());
    cin >> l >> p;

    while(p < l) {
        while(idx<n && p >= v[idx].first) {
            pq.push(v[idx].second);
            idx++;
        }

        if(pq.empty()) {
            flag = true;
            break;
        }

        p += pq.top();
        pq.pop();
        result++;
    }

    if(flag) cout << -1;
    else cout << result;

    return 0;
}