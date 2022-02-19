#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> pii;
#define INF 1987654321

int n, m;
vector<pii> adj[1004];
int d[1004];

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for(int i=0; i<m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({c, b});
    }
    for(int i=0; i<=n; i++) d[i] = INF;

    int s, e;
    cin >> s >> e;

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
            if(d[next]<=d[cur.second]+cost) continue;

            d[next] = d[cur.second] + cost;
            pq.push({d[cur.second]+cost, next});
        }
    }

    cout << d[e];
    return 0;
}