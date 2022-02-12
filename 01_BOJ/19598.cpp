#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
typedef pair<int, int> pii;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, s, e;
    vector<pii> v;
    priority_queue<int, vector<int>, greater<int>> pq;

    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> s >> e;
        v.push_back({s, e});
    }
    sort(v.begin(), v.end());

    int res = 1;
    pq.push(v[0].second);
    for(int i=1; i<n; i++) {
        while(!pq.empty() && (pq.top()<=v[i].first)) pq.pop();
        pq.push(v[i].second);
        res = max(res, (int)pq.size());
    }

    cout << res;
    return 0;
}