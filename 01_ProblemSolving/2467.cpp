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
    int l = 0, r = n-1;
    pair<int, int> result;

    while(l<r) {
        int num = v[l] + v[r];

        if(abs(s) > abs(num)) {
            s = num;
            result.first = v[l];
            result.second = v[r];
        }

        if(num < 0) l++;
        else r--;
    }

    cout << result.first << " " << result.second;

    return 0;
}