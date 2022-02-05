/*

Prim

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> pii;

int main() {
    int n, m;
    int res = 0, mx=0;
    vector<pii> a[100004];
    int visited[100004] = {0,};
    priority_queue<pii, vector<pii>, greater<pii> > pq;

    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for(int i=0; i<m; i++) {
        int x, y, c;
        cin >> x >> y >> c;

        a[x].push_back({y, c});
        a[y].push_back({x, c});
    }

    pq.push({0, 1});

    // 기존 프림 + 가장 큰 가중치 제거 (마을 두개로 분할)
    while(!pq.empty()) {
        int w = pq.top().first;
        int x = pq.top().second;
        pq.pop();

        if(visited[x]==1) continue;

        visited[x] = 1;
        res += w;
        mx = max(mx, w);

        for(int i=0; i<a[x].size(); i++) {
            int ny = a[x][i].first;
            int nw = a[x][i].second;
            pq.push({nw, ny});
        }
    }

    cout << res - mx;
    return 0;
}
*/

// Kruskal

#include <iostream>
#include <tuple>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;
vector<int> parent(100002, -1);
tuple<int, int, int> edge[1000002];

int find(int x) {
    if(parent[x]<0) return x;
    return parent[x] = find(parent[x]);
}

bool is_diff_group(int x, int y) {
    x = find(x);
    y = find(y);
    if(x==y) return 0;
    parent[y] = x;
    return 1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int a, b, c;
    cin >> n >> m;
    for(int i=0; i<m; i++) {
        cin >> a >> b >> c;
        if(a > b) swap(a, b);
        edge[i] = {c, a, b};
    }
    sort(edge, edge+m);

    int mx = 0, res = 0;
    for(int i=0; i<m; i++) {
        int cost, a, b;
        tie(cost, a, b) = edge[i];
        if(!is_diff_group(a, b)) continue;
        res += cost;
        mx = max(mx, cost);
    }

    cout << res - mx;
    return 0;
}