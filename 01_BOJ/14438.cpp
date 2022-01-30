#include <iostream>
#include <vector>
using namespace std;

const int MAX = 100000;
vector<int> v, segtree;

int init(int start, int end, int node) {
    if(start==end) return segtree[node] = v[start];
    int mid = (start + end) / 2;
    return segtree[node] = min(init(start, mid, node*2), init(mid+1, end, node*2+1));
}

int query(int start, int end, int node, int left, int right) {
    if(start > right || end < left) return 1987654321;
    if(left <= start && end <= right) return segtree[node];
    int mid = (start + end) / 2;
    return min(query(start, mid, node*2, left, right), query(mid+1, end, node*2+1, left, right));
}

int update(int start, int end, int node, int idx) {
    if(idx < start || end < idx) return segtree[node];
    if(start==end) return segtree[node] = v[idx];
    int mid = (start + end) / 2;
    return segtree[node] = min(update(start, mid, node * 2, idx), update(mid + 1, end, node * 2 + 1, idx));
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, m;
    cin >> n;

    v.resize(n+4);
    segtree.resize(4*n+4);
    
    for(int i=1; i<=n; i++) {
        cin >> v[i];
    }

    init(1, n, 1);

    cin >> m;
    for(int i=0; i<m; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        if(a==1) {
            v[b] = c;
            update(1, n, 1, b);
        } else {
            cout << query(1, n, 1, b, c) << '\n';
        }
    }

    return 0;
}