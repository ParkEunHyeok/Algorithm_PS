#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for(int i=0; i<n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    int res = 0, idx = 0;
    while(0<=idx && idx<n) {
        if(v[idx]>0) break;
        if(idx%m==0) res += abs(v[idx]) * 2;
        idx++;
    }
    idx = 0;
    while(0<=idx && idx<n) {
        if(v[n-1-idx]<0) break;
        if(idx%m==0) res += abs(v[n-1-idx]) * 2;
        idx++;
    }
    res -= max(abs(v[0]), abs(v[n-1]));

    cout << res;
    return 0;
}