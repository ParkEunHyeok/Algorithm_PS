#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, k;
    vector<int> v;
    
    cin >> n >> k;
    v.resize(n);
    for(int i=0; i<n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    int res = v[n-1] - v[0];
    for(int i=0; i<n-1; i++) {
        v[i] = v[i+1] - v[i];
    }

    v[n-1] = 0;
    sort(v.begin(), v.end(), greater<int>());

    for(int i=0; i<k-1; i++) {
        res -= v[i];
        if(res==0) break;
    }
    
    cout << res;
    return 0;
}