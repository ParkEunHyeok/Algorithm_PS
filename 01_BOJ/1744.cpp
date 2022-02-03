#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, res = 0;
    vector<int> v;

    cin >> n;
    v.resize(n);
    for(int i=0; i<n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    bool zero = false;
    int m = 0, p = 0;
    int c = 0;

    for(int i=0; i<n; i++) {
        if(v[i]==0) {
            zero = true;
            break;
        }
        else if(v[i]>0) break;

        c = (c+1)%2;
        if(c==1) m = v[i];
        else res += v[i-1]*v[i];
    }
    if(c==0) m = 0;

    c = 0;
    for(int i=n-1; i>=0; i--) {
        if(v[i]<=0) break;

        c = (c+1)%2;
        if(c==1) p = v[i];
        else {
            if(v[i]==1) res += v[i+1]*v[i]+1;
            else res += v[i+1]*v[i];
        }
    }
    if(c==0) p = 0;

    if(zero) res += p;
    else res += m + p;

    cout << res;
    return 0;
}