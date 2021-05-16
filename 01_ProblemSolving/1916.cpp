#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define INF 987654321

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int V, E, start, end;
    cin >> V >> E;

    priority_queue<pair<int, int> > pq;
    vector<pair<int, int> > arr[V+1];
    int dist[V+1];

    for(int i=0; i<V+1; i++) {
        dist[i] = INF;
    }

    for(int i=0; i<E; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;
        arr[from].push_back(make_pair(to, cost));
    }

    cin >> start >> end;
    pq.push(make_pair(0, start));
    dist[start] = 0;

    while(!pq.empty()) {
        int cost = -pq.top().first;
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

    cout << dist[end];
    return 0;
}