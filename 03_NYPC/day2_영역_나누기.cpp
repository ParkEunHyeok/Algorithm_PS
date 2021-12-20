#include <iostream>
#include <vector>
using namespace std;
#define MAX 500001
#define ll long long

int arr[MAX];
vector<ll> tree;

ll sum(int start, int end, int node, int left, int right) {
    if(end<left || right<start) return 0;
    if(left<=start && end<=right) return tree[node];
    int mid = (start+end)/2;
    return sum(start, mid, node*2, left, right) + sum(mid+1, end, node*2+1, left, right);
}

void update(int start, int end, int node, int idx, ll diff) {
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

    int n;
    ll answer = 1;

    cin >> n;
    tree.resize(4*(n*2)+4, 0);

    for(int i=1; i<=(n*2); i++) {
        int tmp;
        cin >> tmp;
        if(arr[tmp]==0) arr[tmp] = i;
        else {
            update(1, 2*n, 1, i, 1);
            answer += sum(1, 2*n, 1, arr[tmp], i);
            update(1, 2*n, 1, arr[tmp], -1);
        }
    }

    cout << answer;
    return 0;
}