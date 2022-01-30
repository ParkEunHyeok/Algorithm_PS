#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll n, m;
    cin >> n >> m;
    vector<ll> v(n);
    ll left=0, right=0;
    for(int i=0; i<n; i++) {
        cin >> v[i];
        right = max(right, v[i]);
    }

    ll result = 0;
    while(left <= right) {
        ll mid = (left + right) / 2;
        ll sum = 0;
        for(int i=0; i<n; i++) {
            if((v[i]-mid)>0) sum += v[i] - mid;
        }

        if(sum >= m) {
            result = max(result, mid);
            left = mid + 1;
        }
        else right = mid - 1;
    }

    cout << result;
    return 0;
}