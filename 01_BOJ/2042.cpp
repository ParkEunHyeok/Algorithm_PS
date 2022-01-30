#include <iostream>
#include <vector>
using namespace std;
#define ll long long

vector<ll> v;
vector<ll> segtree;

ll init(int start, int end, int node) {
    if(start==end) return segtree[node] = v[start];
    int mid = (start + end) / 2;
    return segtree[node] = init(start, mid, node*2) + init(mid+1, end, (node*2)+1);
}

ll sum(int start, int end, int node, int left, int right) {
    if(left > end || right < start) return 0;
    if(left <= start && right >= end) return segtree[node];
    int mid = (start + end) / 2;
    return sum(start, mid, node*2, left, right) + sum(mid+1, end, (node*2)+1, left, right);
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

    int n, m, k;
    cin >> n >> m >> k;
    segtree.resize(4*n+1);

    for(int i=0; i<n; i++) {
        ll tmp;
        cin >> tmp;
        v.push_back(tmp);
    }

    init(0, n-1, 1);

    for(int i=0; i<m+k; i++) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        
        if(a==1) {  // b번째 수를 c로 바꾸기
            int idx = b-1;
            ll target = c;
            ll diff = c - v[idx];
            v[idx] = target;
            update(0, n-1, 1, idx, diff);
        }
        else {  // b~c 구간합 구하기
            int left = b-1;
            int right = c-1;
            cout << sum(0, n-1, 1, left, right) << "\n";
        }
    }

    return 0;
}