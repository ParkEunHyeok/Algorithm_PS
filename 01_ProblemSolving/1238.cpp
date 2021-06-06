#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define INF 987654321
typedef pair<int, int> pii;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m, x;
    int max_dist = 0;
    cin >> n >> m >> x;

    priority_queue<pii, vector<pii>, greater<pii> > pq;
    vector<pii> map[n+1];
    vector<pii> map_rev[n+1];
    int dist[n+1];
    int dist_rev[n+1];

    for(int i=0; i<m; i++) {
        int from, to, d;
        cin >> from >> to >> d;
        map[from].push_back({to, d});
        map_rev[to].push_back({from, d});
    }

    for(int i=0; i<n+1; i++) {
        dist[i] = INF;
        dist_rev[i] = INF;
    }

    dist[x] = 0;
    pq.push({0, x});
    // 다익스트라 : 출발점에서 도착점으로
    while(!pq.empty()) {
        int cost = pq.top().first;
        int idx = pq.top().second;
        pq.pop();

        for(int i=0; i<map[idx].size(); i++) {
            int nextIdx = map[idx][i].first;
            int nextCost = map[idx][i].second;

            if(dist[nextIdx] > dist[idx] + nextCost) {
                dist[nextIdx] = dist[idx] + nextCost;
                pq.push({nextCost, nextIdx});
            }
        }
    }

    dist_rev[x] = 0;
    pq.push({0, x});
    // 다익스트라 : 출발점에서 도착점으로
    while(!pq.empty()) {
        int cost = pq.top().first;
        int idx = pq.top().second;
        pq.pop();

        for(int i=0; i<map_rev[idx].size(); i++) {
            int nextIdx = map_rev[idx][i].first;
            int nextCost = map_rev[idx][i].second;

            if(dist_rev[nextIdx] > dist_rev[idx] + nextCost) {
                dist_rev[nextIdx] = dist_rev[idx] + nextCost;
                pq.push({nextCost, nextIdx});
            }
        }
    }

    for(int i=0; i<n+1; i++) {
        if(dist[i]==INF || dist_rev[i]==INF) continue;
        
        max_dist = max(max_dist, dist[i] + dist_rev[i]);
    }

    cout << max_dist;
    return 0;
}