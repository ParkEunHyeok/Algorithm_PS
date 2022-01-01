#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
#define ll long long

int main() {
    int n;
    vector<pair<int, int> > v;

    cin >> n;
    v.resize(n);
    for(int i=n-1; i>=0; i--) {
        int x, y;
        cin >> x >> y;
        v[i] = {x,y};
    }

    ll res = 0;
    for(int i=0; i<n; i++) {
        ll a = v[i].first;
        ll b, c;
        
        if(i+1>=n) b = v[i+1-n].second;
        else b = v[i+1].second;

        if(i+2>=n) c = v[i+2-n].second;
        else c = v[i+2].second;

        res += a*(b-c);
    }

    printf("%.1Lf", (long double)res / 2);
    return 0;
}