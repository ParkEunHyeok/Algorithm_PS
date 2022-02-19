#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int v, e, k;
// 비용, 정점 번호
vector<pii> adj[20005];
const int INF = 1987654321;
int d[20005];    // 최단 거리 테이블

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> v >> e >> k;
    for(int i=0; i<e; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({c, b});   
    }
    for(int i=0; i<=v; i++) {
        d[i] = INF;
    }

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    d[k] = 0;
    pq.push({0, k});

    while(!pq.empty()) {
        int cost = pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        if(d[cur]!=cost) continue;

        for(int i=0; i<adj[cur].size(); i++) {
            int next = adj[cur][i].second;
            int c = adj[cur][i].first;
            if(d[next] <= d[cur]+c) continue;
            d[next] = d[cur] + c;
            pq.push({d[cur]+c, next});
        }
    }

    for(int i=1; i<=v; i++) {
        if(d[i]==INF) cout << "INF\n";
        else cout << d[i] << "\n";
    }
    return 0;
}