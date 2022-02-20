#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, l, s, e;
    vector<pair<int, int>> v;

    cin >> n >> l;
    for(int i=0; i<n; i++) {
        cin >> s >> e;
        v.push_back({s, e});
    }
    sort(v.begin(), v.end());

    int idx = 0, res = 0;
    for(int i=0; i<n; i++) {
        if(idx >= v[i].second) continue;

        idx = max(idx, v[i].first);
        int cnt = (v[i].second - (idx+1))/l +1;
        res += cnt;
        idx += l * cnt;
    }

    cout << res;
    return 0;
}