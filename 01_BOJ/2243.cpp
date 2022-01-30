#include <iostream>
#include <vector>
using namespace std;
#define MAX 1000001
#define ll long long

vector<int> tree(4*MAX), v(MAX);
int res;

void update(int start, int end, int node, int idx, int diff) {
    if(idx < start || end < idx) return;
    tree[node] += diff;
    if(start==end) return;
    int mid = (start+end)/2;
    update(start, mid, node*2, idx, diff);
    update(mid+1, end, node*2+1, idx, diff);
}   

ll query(int start, int end, int node, int k) {
    if(start==end && res==0) {
        cout << start << "\n";
        return start;
    }

    if((res==0) && (node*2<=tree.size()) && tree[node*2]>=k)
        return res = query(start, (start+end)/2, node*2, k);
    k -= tree[node*2];
    if((res==0) && (node*2+1<=tree.size()) && tree[node*2+1]>=k)
        return res = query((start+end)/2+1, end, node*2+1, k);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        if(n==1) {
            int idx;
            cin >> idx;
            int index = query(0, MAX-1, 1, idx);
            res = 0;
            update(0, MAX-1, 1, index, -1);
        }
        else if(n==2) {
            int idx, value;
            cin >> idx >> value;
            update(0, MAX-1, 1, idx, value);
        }
    }

    return 0;
}