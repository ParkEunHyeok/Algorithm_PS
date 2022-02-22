#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef pair<int, int> pii;

int v, e;
int A, B, C;
vector<pii> adj[100002];
const int INF = 1987654321;
vector<int> dist, d;

void dijk(int s) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, s});
    for(int i=0; i<=v; i++) d[i] = INF;
    d[s] = 0;

    while(!pq.empty()) {
        int cost = pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        if(d[cur]!=cost) continue;

        for(int i=0; i<adj[cur].size(); i++) {
            int nCost = adj[cur][i].first;
            int next = adj[cur][i].second;
            if(d[next]<=d[cur]+nCost) continue;
            d[next] = d[cur] + nCost;
            pq.push({d[next], next});
        }
    }

    for(int i=1; i<=v; i++) {
        if(i==s) continue;
        dist[i] = min(dist[i], d[i]);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> v >> A >> B >> C >> e;
    for(int i=0; i<e; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({c, b});
        adj[b].push_back({c, a});
    }
    dist.resize(v+1);
    d.resize(v+1);
    for(int i=0; i<=v; i++) {
        dist[i] = INF;
    }

    dijk(A);
    dijk(B);
    dijk(C);

    int mx = 0, mx_idx = 0;
    for(int i=1; i<=v; i++) {
        if(mx < dist[i]) {
            mx = dist[i];
            mx_idx = i;
        }
    }

    cout << mx_idx;
    return 0;
}