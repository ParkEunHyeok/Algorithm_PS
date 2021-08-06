#include <iostream>
#include <vector>
using namespace std;
#define ll long long

vector<ll> v;
vector<ll> segtree;

ll init(int start, int end, int node) {
    if(start==end) return segtree[node] = v[start];
    int mid = (start+end)/2;
    return segtree[node] = init(start, mid, node*2) + init(mid+1, end, node*2+1);
}

ll sum(int start, int end, int node, int left, int right) {
    if(left > end || right < start) return 0;
    if(left <= start && end <= right) return segtree[node];
    int mid = (start + end) / 2;
    return sum(start, mid, node*2, left, right) + sum(mid+1, end, node*2+1, left, right);
}

void update(int start, int end, int node, int idx, ll diff) {
    if(idx < start || idx > end) return;
    segtree[node] += diff;

    if(start==end) return;
    int mid = (start + end) / 2;
    update(start, mid, node*2, idx, diff);
    update(mid+1, end, node*2+1, idx, diff);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;
    v.resize(n+4);
    segtree.resize(4*n+4);

    for(int i=0; i<m; i++) {
        ll a, b, c;
        cin >> a >> b >> c;

        if(a==0) {
            if(b>c) swap(b, c);
            int left = b-1;
            int right = c-1;
            cout << sum(0, n-1, 1, left, right) << '\n';
        } else {
            int idx = b-1;
            ll diff = c - v[idx];
            v[idx] = c;
            update(0, n-1, 1, idx, diff);
        }
    }

    return 0;
}