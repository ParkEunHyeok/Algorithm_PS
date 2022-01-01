#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    int preSum = 0;
    vector<int> v;

    cin >> n;
    v.resize(n);

    for(int i=0; i<n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    if(v[0] > 1) cout << 1;
    else {
        preSum += v[0];
        for(int i=1; i<n; i++) {
            if(preSum+1 < v[i]) break;
            preSum += v[i];
        }

        cout << preSum+1;
    }

    return 0;
}