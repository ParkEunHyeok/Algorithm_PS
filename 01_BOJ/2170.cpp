#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define INF 1987654321

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    vector<pair<int, int>> v;

    cin >> n;
    for(int i=0; i<n; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }
    sort(v.begin(), v.end());

    int res = 0;
    int s = -INF, e = -INF;
    for(int i=0; i<n; i++) {
        if(e < v[i].first) {
            res += e - s;
            s = v[i].first;
            e = v[i].second;
        } else e = max(e, v[i].second);
    }
    res += e - s;

    cout << res;
    return 0;
}