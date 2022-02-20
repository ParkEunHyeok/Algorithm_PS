#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define ll long long
typedef pair<int, int> pii;

int n, e, v1, v2;
vector<pii> adj[802];
int d[802];

void dijk(int s) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    d[s] = 0;
    pq.push({0, s});

    while(!pq.empty()) {
        pii cur = pq.top();
        pq.pop();
        if(d[cur.second]!=cur.first) continue;

        for(int i=0; i<adj[cur.second].size(); i++) {
            int next = adj[cur.second][i].second;
            int cost = adj[cur.second][i].first;
            if(d[next] <= d[cur.second]+cost) continue;

            d[next] = d[cur.second] + cost;
            pq.push({d[next], next});
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll res = INF;
    cin >> n >> e;
    for(int i=0; i<e; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({c, b});
        adj[b].push_back({c, a});
    }
    cin >> v1 >> v2;

    for(int i=0; i<=n; i++) d[i] = INF;
    dijk(1);
    ll route1 = d[v1], route2 = d[v2];

    for(int i=0; i<=n; i++) d[i] = INF;
    dijk(v1);
    route1 += d[v2];
    route2 += d[n];

    for(int i=0; i<=n; i++) d[i] = INF;
    dijk(v2);
    route1 += d[n];
    route2 += d[v1];

    res = min(res, min(route1, route2));

    if(res>=INF) cout << -1;
    else cout << res;
    return 0;
}