#include <iostream>
using namespace std;
#define ll long long

int main() {
    ll d, n, m, k, res;
    cin >> d >> n >> m >> k;

    ll a1 = d - (n%d);
    ll a2 = d - (m%d);

    if(a1 > a2) swap(a1, a2);

    ll ans1 = k - a1 - a2;
    ll ans2 = k - a1;
    ll ans3 = k;

    if(ans1/d+2 == ans2/d+1) {
        if(ans3/d == ans1/d+2) res = ans3;
        else res = ans2;
    } else res = ans1;

    cout << res;
    return 0;
}