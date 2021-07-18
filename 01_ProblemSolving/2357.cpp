#include <iostream>
#include <vector>
using namespace std;

vector<int> v;
vector<pair<int, int>> tree;    // 최솟값, 최댓값

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
    if(start > right || end < left) return {987654321, 0};
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

    v.resize(n);
    tree.resize(4*n+1);

    for(int i=0; i<n; i++) {
        cin >> v[i];
    }

    init(0, n-1, 1);
    
    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        pair<int, int> res = query(0, n-1, 1, a-1, b-1);
        cout << res.first << ' ' << res.second << '\n';
    }

    return 0;
}