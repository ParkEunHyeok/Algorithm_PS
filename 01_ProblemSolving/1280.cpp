#include <iostream>
#include <vector>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 200001

vector<ll> dist, cnt;

void update_dist(int start, int end, int node, int idx, int diff) {
    if(idx < start || end < idx) return;
    dist[node] += diff;
    if(start==end) return;
    int mid = (start+end)/2;
    update_dist(start, mid, node*2, idx, diff);
    update_dist(mid+1, end, node*2+1, idx, diff);
}

void update_cnt(int start, int end, int node, int idx, int diff) {
    if(idx < start || end < idx) return;
    cnt[node] += diff;
    if(start==end) return;
    int mid = (start+end)/2;
    update_cnt(start, mid, node*2, idx, diff);
    update_cnt(mid+1, end, node*2+1, idx, diff);
}

ll dist_sum(int start, int end, int node, int left, int right) {
    if(right < start || end < left) return 0;
    if(left <= start && end <= right) return dist[node];
    int mid = (start+end)/2;
    return dist_sum(start, mid, node*2, left, right) + dist_sum(mid+1, end, node*2+1, left, right);
}

ll cnt_sum(int start, int end, int node, int left, int right) {
    if(right < start || end < left) return 0;
    if(left <= start && end <= right) return cnt[node];
    int mid = (start+end)/2;
    return cnt_sum(start, mid, node*2, left, right) + cnt_sum(mid+1, end, node*2+1, left, right);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    dist.resize(4*MAX, 0);
    cnt.resize(4*MAX, 0);

    int tmp;
    cin >> tmp;
    update_dist(0, MAX-1, 1, tmp, tmp);
    update_cnt(0, MAX-1, 1, tmp, 1);

    ll ans = 1;
    for(int i=1; i<n; i++) {
        cin >> tmp;
        update_dist(0, MAX-1, 1, tmp, tmp);
        update_cnt(0, MAX-1, 1, tmp, 1);
    
        ll sum1 = dist_sum(0, MAX-1, 1, 0, tmp-1);
        ll sum2 = dist_sum(0, MAX-1, 1, tmp+1, dist.size());
        ll cnt1 = cnt_sum(0, MAX-1, 1, 0, tmp-1);
        ll cnt2 = cnt_sum(0, MAX-1, 1, tmp+1, cnt.size());
    
        ll cost = (sum2-tmp*cnt2)%MOD + (tmp*cnt1-sum1)%MOD;
        ans *= cost%MOD;
        ans %= MOD;
    }

    cout << ans;
    return 0;
}