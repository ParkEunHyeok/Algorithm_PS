#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> pos, v, segtree;

int sum(int start, int end, int node, int left, int right) {
    if(left > end || start > right) return 0;
    if(left <= start && end <= right) return segtree[node];
    int mid = (start+end)/2;
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

    pos.resize(n+1);
    v.resize(n+1);
    segtree.resize(4*n+4);

    for(int i=1; i<=n; i++) {
        int tmp;
        cin >> tmp;
        pos[tmp] = i;
    }

    for(int i=1; i<=n; i++) {
        update(1, n, 1, pos[i], 1);
    }

    int left = 1, right = n;
    int mid = (left+right)/2;
    int c = n;

    while(c--) {
        if(left <= mid) {
            cout << sum(1, n, 1, 1, pos[left] - 1) << "\n";
            update(1, n, 1, pos[left], -1);
            left++;
        }
        if(mid+1 <= right) {
            cout << sum(1, n, 1, pos[right]+1, n) << "\n";
            update(1, n, 1, pos[right], -1);
            right--;
        }
    }

    return 0;
}