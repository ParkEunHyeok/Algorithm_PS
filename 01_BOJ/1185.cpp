#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;

vector<int> country, parent;
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

    int n, p;
    int mn=10000, mn_idx;
    
    cin >> n >> p;
    country.resize(n+1);
    parent.resize(n+1);

    for(int i=1; i<=n; i++) {
        cin >> country[i];

        if(country[i]<mn) {
            mn = country[i];
            mn_idx = i;
        }
    }
    for(int i=0; i<p; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edge.push_back({2*c+country[a]+country[b], a, b});
    }
    sort(edge.begin(), edge.end());

    for(int i=0; i<=n; i++) parent[i] = i;
    parent[mn_idx] = 0;

    int dist = 0;
    for(int i=0; i<p; i++) {
        int cost, a, b;
        tie(cost, a, b) = edge[i];
        if(!is_diff_group(a, b)) continue;
        dist += cost;
    }
    dist += country[mn_idx];

    cout << dist;
    return 0;
}