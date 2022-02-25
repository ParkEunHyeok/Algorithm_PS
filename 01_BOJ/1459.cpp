#include <iostream>
using namespace std;
#define ll long long

int main() {
    ll x, y, w, s;
    ll ans = 0;
    cin >> x >> y >> w >> s;

    if(2*w >= s) {
        ans += s*min(x, y);
    } else {
        ans += (2*min(x,y))*w;
    }

    ll d = (max(x, y)-min(x, y));
    if(d%2==1) {
        ans += w;
        d--;
    }

    if(2*w >= 2*s) {
        ans += s * d;
    } else ans += w * d;

    cout << ans;
    return 0;
}