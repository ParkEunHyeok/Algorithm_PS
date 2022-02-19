#include <iostream>
#include <queue>
using namespace std;
#define ll long long
typedef pair<ll, ll> pll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, t, p;
    ll sum=0, cnt=0, res=0;
    priority_queue<int> pq;
    
    cin >> n >> t >> p;
    for(int i=0; i<n; i++) {
        int tmp;
        cin >> tmp;
        pq.push(tmp);
        sum += tmp;
        cnt++;

        while(!pq.empty() && ((ll)i*p + sum > t)) {
            if((ll)i*p > t) {
                sum = cnt = 0;
                break;
            }
            sum -= pq.top();
            pq.pop();
            cnt--;
        }

        res = max(res, cnt);
    }

    cout << res;
    return 0;
}