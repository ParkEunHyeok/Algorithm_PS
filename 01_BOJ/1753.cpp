/*
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

    for(int i=1; i<=V; i++) {
        if(dist[i]>=INF) {
            cout << "INF\n";
            continue;
        }
        cout << dist[i] << "\n";
    }
    return 0;
}
*/

#include <iostream>
#include <vector>
using namespace std;
#define INF 1987654321

/*
    최단거리
    정답 : 0 2 3 1 2 4
*/

int v, e, k;
// 간선 정보를 저장할 배열
int edges[20002][20002];
bool visited[20002] = {0,};
int dists[20002] = {0,};

// distance 배열에서 모든 노드를 탐색하여 가장 적은 값을 가지는 노드를 반환
int getSmallIndex() {
    int minValue = INF;
    int minIndex = INF;
    for(int i=0; i<v; i++) {
        if(visited[i]==true) continue;
        if(dists[i] < minValue) {
            minValue = dists[i];
            minIndex = i;
        }
    }

    return minIndex;
}

/*
    다익스트라
    1. dists 배열을 시작노드의 값으로 초기화함
    2. 시작노드 방문처리
    3. 최단거리를 계산해나갈 배열 dists에서 가장 최소거리를 가지는 최솟값
*/
void dijkstra(int startNode) {
    // 1. dists 배열을 시작노드의 값으로 초기화함
    for(int i=0; i<v; i++) dists[i] = edges[startNode][i];

    // 2. 시작노드 방문처리
    visited[startNode] = true;

    // 시작노드는 방문하였으므로 NODE_COUNT-1까지 확인
    for(int i=0; i<v; i++) {
        // 3. 최단거리를 계산해나갈 배열 dists에서 가장 최소거리를 가지는 최솟값
        int current = getSmallIndex();
        if(current==INF) continue;

        visited[current] = true;
        // 모든 노드를 검사하여 j번째 노드를 거쳐가는 경우의 비용이 더 작다면 갱신함
        for(int j=0; j<v; j++) {
            if(visited[j]) continue;
            
            // 현재 선택된 노드(dists[current])를 거쳐갈 경우 더 적은값을 가지는지 확인함
            // 거쳐가는 경우 - dists[current] + edges[current]
            // 한번에 가는 경우 dists[j]
            if(dists[j] > dists[current] + edges[current][j])
                dists[j] = dists[current] + edges[current][j];
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> v >> e >> k;
    for(int i=0; i<e; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edges[a][b] = c;
        edges[b][a] = c;
    }
    for(int i=0; i<v; i++) dists[i] = INF;

    dijkstra(k-1);
    
    for(int i=0; i<v; i++) {
        if(dists[i]==INF) cout << "INF\n";
        else cout << dists[i] << "\n";
    }
    return 0;
}