#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vector<int> v(n);

    for(int i=0; i<n; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    long long res = 0;
    for(int i=1; i<=n; i++) {
        res += abs(v[i-1]-i);
    }

    cout << res;
    return 0;
}