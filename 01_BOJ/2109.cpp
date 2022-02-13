#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    vector<pii> v;
    priority_queue<int, vector<int>, greater<int>> pq;

    cin >> n;
    for(int i=0; i<n; i++) {
        int d, p;
        cin >> p >> d;
        v.push_back({d, p});
    }
    sort(v.begin(), v.end());

    for(int i=0; i<n; i++) {
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