#include <iostream>
#include <queue>
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int c;
    cin >> c;
    while(c--) {
        ll n, tmp;
        priority_queue<ll, vector<ll>, greater<ll>> pq;

        cin >> n;
        for(int i=0; i<n; i++) {
            cin >> tmp;
            pq.push(tmp);
        }

        ll res = 0;
        while(pq.size() >= 2) {
            ll a = pq.top();
            pq.pop();
            ll b = pq.top();
            pq.pop();
            
            res += a + b;
            pq.push(a+b);
        }

        cout << res << "\n";
    }

    return 0;
}