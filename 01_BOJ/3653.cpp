#include <iostream>
#include <vector>
using namespace std;

int n, m;
int treeSize;
vector<int> v, tree;

int init(int start, int end, int node, int m) {
    if(start==end) {
        if(start >= m) {
            v[start-m] = start;
            tree[node] = 1;
        }
        return tree[node];
    }

    int mid = (start+end)/2;
    return tree[node] = init(start, mid, node*2, m) + init(mid+1, end, node*2+1, m);
}

int sum(int start, int end, int node, int left, int right) {
    if(right < start || end < left) return 0;
    if(left <= start && end <= right) return tree[node];
    int mid = (start+end)/2;
    return sum(start, mid, node*2, left, right) + sum(mid+1, end, node*2+1, left, right);
}

void update(int start, int end, int node, int idx, int diff) {
    if(idx < start || end < idx) return;
    tree[node] += diff;
    if(start==end) return;
    int mid = (start+end)/2;
    update(start, mid, node*2, idx, diff);
    update(mid+1, end, node*2+1, idx, diff);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while(t--) {
        cin >> n >> m;
        
        treeSize = n + m;

        v.clear();
        tree.clear();
        v.resize(n, 0);
        tree.resize(4*treeSize+4, 0);

        init(0, treeSize-1, 1, m);

        int index = m-1;
        for(int i=0; i<m; i++) {
            int tmp;
            cin >> tmp;

            cout << sum(0, treeSize-1, 1, 0, v[tmp-1]-1) << " ";
            update(0, treeSize-1, 1, v[tmp-1], -1);
            v[tmp-1] = index;
            update(0, treeSize-1, 1, v[tmp-1], 1);
            index--;
        }
        cout << "\n";
    }

    return 0;
}