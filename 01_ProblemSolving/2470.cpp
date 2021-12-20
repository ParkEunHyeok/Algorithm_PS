#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    vector<int> v(n);

    for(int i=0; i<n; i++) {
        int tmp;
        cin >> tmp;
        v[i] = tmp;
    }
    sort(v.begin(), v.end());

    ll s = 2000000001;
    bool flag = false;
    pair<int, int> result;

    for(int i=0; i<n; i++) {
        if(v[i]>0) break;
        
    }

    if(result.first < result.second) {
        cout << result.first << " " << result.second;
    } else {
        cout << result.second << " " << result.first;
    }

    return 0;
}