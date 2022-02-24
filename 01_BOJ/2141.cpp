#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, ans=0;
    ll s1=0, s2=0;
    ll diff = 1e10;
    vector<pair<int, int>> v;

    cin >> n;
    for(int i=0; i<n; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
        s1 += b;
    }
    sort(v.begin(), v.end());

    for(int i=0; i<n; i++) {
        s2 += v[i].second;
        ll d = abs(s1-s2);
        if(diff > d) {
            ans = v[i].first;
            diff = d;
        }
        s1 -= v[i].second;
    }

    cout << ans;
    return 0;
}