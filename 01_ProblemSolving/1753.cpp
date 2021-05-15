#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define INF 987654321

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int V, E, start;
    cin >> V >> E >> start;
    
    priority_queue<pair<int, int> > pq;
    vector<pair<int, int> > arr[V+1];
    int dist[V+1];

    for(int i=0; i<V+1; i++) {
        dist[i] = INF;
    }

    for(int i=0; i<E; i++) {
        int from, to, distance;
        cin >> from >> to >> distance;
        arr[from].push_back(make_pair(to, distance));
    }
    pq.push(make_pair(0, start));
    dist[start] = 0;

    while(!pq.empty()) {
        int cost = pq.top().first;
        int idx = pq.top().second;
        pq.pop();

        for(int i=0; i<arr[idx].size(); i++) {
            int nextIdx = arr[idx][i].first;
            int nextCost = arr[idx][i].second;

            if(dist[nextIdx] > dist[idx] + nextCost) {
                dist[nextIdx] = dist[idx] + nextCost;
                pq.push(make_pair(-dist[nextIdx], nextIdx));
            }
        }
    }

    for(int i=1; i<=V; i++) {
        if(dist[i]>=INF) {
            cout << "INF\n";
            continue;
        }
        cout << dist[i] << "\n";
    }
    return 0;
}