#include <iostream>
#include <vector>
using namespace std;

vector<int> result, tree;
int res;

void init(int start, int end, int node) {
    if(start==end) {
        tree[node] = 1;
        return;
    }
    int mid = (start+end)/2;
    init(start, mid, node*2);
    init(mid+1, end, node*2+1);
    tree[node] = tree[node*2] + tree[node*2+1];
}

void update(int start, int end, int node, int idx, int diff) {
    if(idx < start || end < idx) return;
    tree[node] += diff;
    if(start==end) return;
    int mid = (start+end)/2;
    update(start, mid, node*2, idx, diff);
    update(mid+1, end, node*2+1, idx, diff);
}

int query(int start, int end, int node, int k) {
    if(start==end && res==0) return start;

    if((res==0) && (node*2<=tree.size()) && tree[node*2]>k)
        return res = query(start, (start+end)/2, node*2, k);
    k -= tree[node*2];
    if((res==0) && (node*2+1<=tree.size()) && tree[node*2+1]>k)
        return res = query((start+end)/2+1, end, node*2+1, k);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;

    tree.resize(4*n+4);
    result.resize(n+1);
    init(1, n, 1);

    for(int i=1; i<=n; i++) {
        int tmp;
        cin >> tmp;
        int index = query(1, n, 1, tmp);
        res = 0;
        result[index] = i;
        update(1, n, 1, index, -1);
    }

    for(int i=1; i<=n; i++) {
        cout << result[i] << '\n';
    }
    return 0;
}