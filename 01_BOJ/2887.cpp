#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int parent[100002];
vector<pair<int, pair<int, int>>> edge;

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

    int n, a, b, c;
    vector<pair<int, int>> x, y, z;

    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> a >> b >> c;
        x.push_back({a, i});
        y.push_back({b, i});
        z.push_back({c, i});
    }

    for(int i=0; i<n; i++) parent[i] = i;

    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    sort(z.begin(), z.end());
    for(int i=0; i<n-1; i++) {
        edge.push_back({x[i+1].first-x[i].first, {x[i].second, x[i+1].second}});
        edge.push_back({y[i+1].first-y[i].first, {y[i].second, y[i+1].second}});
        edge.push_back({z[i+1].first-z[i].first, {z[i].second, z[i+1].second}});
    }
    sort(edge.begin(), edge.end());

    int cnt = 0, res = 0;
    for(int i=0; i<edge.size(); i++) {
        int a = edge[i].second.first;
        int b = edge[i].second.second;
        int cost = edge[i].first;
        if(!is_diff_group(a, b)) continue;
        res += cost;
        cnt++;
        if(cnt==n-1) break;
    }

    cout << res;
    return 0;
}