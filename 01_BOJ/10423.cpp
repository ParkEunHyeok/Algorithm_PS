#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
using namespace std;

vector<int> parent(1002);
vector<tuple<int, int, int>> edge;

int find(int x) {
    if(parent[x]==x) return x;
    return parent[x] = find(parent[x]);
}

bool is_diff_group(int x, int y) {
    x = find(x);
    y = find(y);
    if(x==y) return 0;

    if(x>y) swap(x, y);
    parent[y] = x;
    return 1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m, k, tmp;
    int u, v, w;

    parent[0] = 0;
    for(int i=1; i<=1000; i++) parent[i] = i;

    cin >> n >> m >> k;
    for(int i=0; i<k; i++) {
        cin >> tmp;
        parent[tmp] = 0;
    }
    for(int i=0; i<m; i++) {
        cin >> u >> v >> w;
        edge.push_back({w, u, v});
    }
    sort(edge.begin(), edge.end());

    int res = 0;
    for(int i=0; i<m; i++) {
        int cost, a, b;
        tie(cost, a, b) = edge[i];
        if(!is_diff_group(a, b)) continue;
        res += cost;
    }

    cout << res;
    return 0;
}