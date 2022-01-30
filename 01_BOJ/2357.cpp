#include <iostream>
using namespace std;
#define MAX 100001

int v[MAX];
pair<int, int> tree[4*MAX];

pair<int, int> init(int start, int end, int node) {
    if(start==end) {
        tree[node].first = v[start];
        tree[node].second = v[start];
        return tree[node];
    }
    
    int mid = (start + end) / 2;
    pair<int, int> left = init(start, mid, node*2);
    pair<int, int> right = init(mid+1, end, node*2+1);
    tree[node].first = min(left.first, right.first);
    tree[node].second = max(left.second, right.second);
    return tree[node];
}

pair<int, int> query(int start, int end, int node, int left, int right) {
    if(start > right || end < left) return {1987654321, 0};
    if(left <= start && end <= right) return tree[node];

    int mid = (start + end) / 2;
    pair<int, int> l = query(start, mid, node*2, left, right);
    pair<int, int> r = query(mid+1, end, node*2+1, left, right);

    pair<int, int> result;
    result.first = min(l.first, r.first);
    result.second = max(l.second, r.second);
    return result;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;

    for(int i=1; i<=n; i++) {
        cin >> v[i];
    }

    init(1, n, 1);
    
    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        pair<int, int> res = query(1, n, 1, a, b);
        cout << res.first << " " << res.second << "\n";
    }

    return 0;
}