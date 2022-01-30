#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int arr[1000001];
vector<ll> v, segtree;

ll sum(int start, int end, int node, int left, int right) {
    if(left > end || right < start) return 0;
    if(left<=start && end<=right) return segtree[node];
    int mid = (start + end) / 2;
    return sum(start, mid, node*2, left, right) + sum(mid+1, end, node*2+1, left, right);
}

void update(int start, int end, int node, int idx, int diff) {
    if(idx < start || end < idx) return;
    segtree[node] += diff;
    if(start==end) return;
    
    int mid = (start+end)/2;
    update(start, mid, node*2, idx, diff);
    update(mid+1, end, node*2+1, idx, diff);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    v.resize(n+1);
    segtree.resize(4*n+4);

    for(int i=1; i<=n; i++) {
        int tmp;
        cin >> tmp;
        arr[tmp] = i;
    }
    for(int i=1; i<=n; i++) {
        int tmp;
        cin >> tmp;
        v[i] = arr[tmp];
    }

    ll ans = 0;
    for(int i=1; i<=n; i++) {
        int tmp = v[i];
        ans += sum(1, n, 1, tmp+1, n);
        update(1, n, 1, tmp, 1);
    }

    cout << ans;
    return 0;
}