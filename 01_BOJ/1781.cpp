#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, a, b;
    vector<pair<int, int>> v;
    priority_queue<int, vector<int>, greater<int>> pq;

    cin >> n;
    while(n--) {
        cin >> a >> b;
        v.push_back({a, b});
    }
    sort(v.begin(), v.end());

    for(int i=0; i<v.size(); i++) {
        if(pq.size() < v[i].first) pq.push(v[i].second);
        else if(pq.top() < v[i].second) {
            pq.pop();
            pq.push(v[i].second);
        }
    }

    int res = 0;
    while(!pq.empty()) {
        res += pq.top();
        pq.pop();
    }

    cout << res;
    return 0;
}